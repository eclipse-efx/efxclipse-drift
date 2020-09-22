/* ******************************************************************************
 * Copyright (c) 2019, 2020 BestSolution.at and others.
 * All rights reserved. This program and the accompanying materials 
 * are made available under the terms of the Eclipse Public License 2.0 
 * which is available at http://www.eclipse.org/legal/epl-2.0
 *
 * SPDX-License-Identifier: EPL-2.0
 * 
 * Contributors:
 *     Christoph Caks <ccaks@bestsolution.at> - initial API and implementation
 * ******************************************************************************/
import org.gradle.api.logging.Logger
import org.gradle.api.logging.Logging
import groovy.json.JsonSlurper
import okhttp3.*

class GithubAPI {

    OkHttpClient client = new OkHttpClient()
    JsonSlurper slurper = new JsonSlurper()

    Logger logger = Logging.getLogger(GithubAPI.class)

    String orga
    String repo
    String token

    GithubAPI(orga, repo, token) {
        this.orga = orga
        this.repo = repo
        this.token = token
    }

    def getReleases() {
        def req = new Request.Builder()
        .header("Authorization", "token $token")
        .header("Content-Type", "application/json")
        .url("https://api.github.com/repos/$orga/$repo/releases")
        .build()
        def res = client.newCall(req).execute()
        assert res.code == 200
        slurper.parseText(res.body.string())
    }

    def createRelease(tag, commitish, name, body, prerelease) {
        def JSON = MediaType.get("application/json; charset=utf-8")
        def msg = [
            tag_name: tag,
            target_commitish: commitish,
            name: name,
            body: body,
            draft: true,
            prerelease: prerelease
        ]
        def msgj = groovy.json.JsonOutput.toJson(msg);

        if (logger.isInfoEnabled()) {
            logger.info "Sending Request: ${new groovy.json.JsonBuilder(msg).toPrettyString()}"
        }

        def requestBody = RequestBody.create(msgj, JSON)
        def req = new Request.Builder()
        .header("Authorization", "token $token")
        .header("Content-Type", "application/json")
        .url("https://api.github.com/repos/$orga/$repo/releases")
        .post(requestBody)
        .build()

        def res = client.newCall(req).execute()

        def json = res.body.string()
        if (logger.isInfoEnabled()) {
            logger.info "Got Response($res.code): $json"
        }

        assert res.code == 201
        slurper.parseText(json)
    }

    def uploadAsset(uploadUrl, mime, file, name, label) {
        // need to remove the {?name, label} stuff
        uploadUrl = uploadUrl.replaceAll('[{].*[}]', '')
        def mediaType = MediaType.get(mime)

        def reqBody = RequestBody.create(mediaType, file)

        def httpBuilder = HttpUrl.parse(uploadUrl).newBuilder()
        if (name != null) {
            httpBuilder.addQueryParameter('name', name)
        }
        if (label != null) {
            httpBuilder.addQueryParameter('label', label)
        }
        def url = httpBuilder.build()

        def req = new Request.Builder()
        .header("Authorization", "token $token")
        .url(url)
        .post(reqBody)
        .build()

        def res = client.newCall(req).execute()

        assert res.code == 201

        slurper.parseText(res.body.string())
    }

    def modifyRelease(releaseId, tag, draft) {
        def JSON = MediaType.get("application/json; charset=utf-8")
        def msg = [
            tag_name: tag,
            draft: draft
        ]
        def msgj = groovy.json.JsonOutput.toJson(msg);
        println new groovy.json.JsonBuilder(msgj).toPrettyString()
        
        def reqBody = RequestBody.create(msgj, JSON)

        def req = new Request.Builder()
        .header("Authorization", "token $token")
        .header("Content-Type", "application/json")
        .url("https://api.github.com/repos/$orga/$repo/releases/$releaseId")
        .patch(reqBody)
        .build()

        def res = client.newCall(req).execute()

        assert res.code == 200

        slurper.parseText(res.body.string())
    }

    def getReleaseByTagName(tagName) {
        def req = new Request.Builder()
        .header("Authorization", "token $token")
        .header("Content-Type", "application/json")
        .url("https://api.github.com/repos/$orga/$repo/releases/tags/$tagName")
        .build()
        def res = client.newCall(req).execute()
        if (res.code == 404) {
            return null
        }
        assert res.code == 200
        slurper.parseText(res.body.string())
    }

    def getArtifacts(runId) {
        def req = new Request.Builder()
        .header("Authorization", "token $token")
        .header("Content-Type", "application/json")
        .url("https://api.github.com/repos/$orga/$repo/actions/runs/$runId/artifacts")
        .build()

        def res = client.newCall(req).execute()

        assert res.code == 200
        slurper.parseText(res.body.string())
    }

    def downloadArtifact(artifact_url, filename) {
        def req = new Request.Builder()
        .header("Authorization", "token $token")
        .url(artifact_url)
        .build()
        def res = client.newCall(req).execute()
        def target = new File(filename)
        target.withOutputStream { out -> 
            res.body.byteStream().with { inStream ->
                out << inStream
                inStream.close()
            }
        }
    }
}