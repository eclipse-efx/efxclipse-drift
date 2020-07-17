
import groovy.json.JsonSlurper
import okhttp3.*

class GithubAPI {

    OkHttpClient client = new OkHttpClient()
    JsonSlurper slurper = new JsonSlurper()

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

    def createRelease(tag, commitish, name, body) {
        def JSON = MediaType.get("application/json; charset=utf-8")
        def msg = [
            tag_name: tag,
            target_commitish: commitish,
            name: name,
            body: body,
            draft: true,
            prerelease: true
        ]
        def requestBody = RequestBody.create(groovy.json.JsonOutput.toJson(msg), JSON)
        def req = new Request.Builder()
        .header("Authorization", "token $token")
        .header("Content-Type", "application/json")
        .url("https://api.github.com/repos/$orga/$repo/releases")
        .post(requestBody)
        .build()

        def res = client.newCall(req).execute()
        assert res.code == 201
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