/*
 * Copyright (c) 2018 BestSolution and Others. All rights reserved.
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License v. 2.0, which is available at
 * http://www.eclipse.org/legal/epl-2.0.
 *
 * This Source Code may also be made available under the following Secondary
 * Licenses when the conditions for such availability set forth in the
 * Eclipse Public License v. 2.0 are satisfied: GNU General Public License,
 * version 2 with the GNU Classpath Exception, which is available at
 * https://www.gnu.org/software/classpath/license.html.
 *
 * SPDX-License-Identifier: EPL-2.0 OR GPL-2.0 WITH Classpath-exception-2.0
 */

#include <jni.h>

#include <thread>
#include <chrono>
#include <iostream>

#include <GL/glew.h>

#include <DriftFX/GL/GLContext.h>
#include <DriftFX/GL/GLTexture.h>
#include <DriftFX/GL/GLDebug.h>

#include <DriftFX/DriftFX.h>
#include <DriftFX/DriftFXSurface.h>


#include <utils/Logger.h>
#include <utils/JNIHelper.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include <stdio.h>

using namespace std;
using namespace chrono;

using namespace driftfx;
using namespace driftfx::gl;

struct Color {
	GLfloat red;
	GLfloat green;
	GLfloat blue;
};
struct Vertex {
	GLfloat x;
	GLfloat y;
	GLfloat z;
	Color color;
};

string LoadTextResource(string resource) {
	JNIEnv* env = JNIHelper::GetJNIEnv(true);

	LogDebug("sending string to java: " << resource);
	jstring jResource = env->NewStringUTF(resource.c_str());
	LogDebug("jResource = " << jResource);

	jclass cARenderer = env->FindClass("org/eclipse/fx/drift/samples/ARenderer");
	jmethodID mARenderer_loadTextResource = env->GetStaticMethodID(cARenderer, "loadTextResource", "(Ljava/lang/String;)Ljava/lang/String;");

	LogDebug("ARenderer = " << cARenderer);
	LogDebug(".loadTextResource = " << mARenderer_loadTextResource);

	jstring jniData = (jstring) env->CallStaticObjectMethod(cARenderer, mARenderer_loadTextResource, jResource);
	LogDebug("jniData = " << jniData);

	env->DeleteLocalRef(jResource);
	const char* cData = env->GetStringUTFChars(jniData, NULL);
	std::string data(cData);
	env->ReleaseStringUTFChars(jniData, cData);

	return data;
}

GLuint LoadShaders(std::string vertex_file_path, std::string fragment_file_path){

	// Create the shaders
	GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	// Read the Vertex Shader code from the file

	std::string VertexShaderCode = LoadTextResource(vertex_file_path);
//	if (VertexShaderCode) {
//		LogError("Failed to load " << vertex_file_path);
//		return 0;
//	}
	std::string FragmentShaderCode = LoadTextResource(fragment_file_path);
//	if (FragmentShaderCode) {
//		LogError("Failed to load " << fragment_file_path);
//		return 0;
//	}

//	std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);
//
//	if(VertexShaderStream.is_open()){
//		std::stringstream sstr;
//		sstr << VertexShaderStream.rdbuf();
//		VertexShaderCode = sstr.str();
//		VertexShaderStream.close();
//	}else{
//		LogError("Impossible to open " << vertex_file_path << ". Are you in the right directory ?");
//		return 0;
//	}

	// Read the Fragment Shader code from the file
//	std::string FragmentShaderCode;
//	std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
//	if(FragmentShaderStream.is_open()){
//		std::stringstream sstr;
//		sstr << FragmentShaderStream.rdbuf();
//		FragmentShaderCode = sstr.str();
//		FragmentShaderStream.close();
//	}

	GLint Result = GL_FALSE;
	int InfoLogLength;

	// Compile Vertex Shader
	LogDebug("Compiling shader: " << vertex_file_path);
	char const * VertexSourcePointer = VertexShaderCode.c_str();
	glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
	glCompileShader(VertexShaderID);

	// Check Vertex Shader
	glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if ( InfoLogLength > 0 ){
		std::vector<char> VertexShaderErrorMessage(InfoLogLength+1);
		glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
		LogInfo(&VertexShaderErrorMessage[0]);
	}

	// Compile Fragment Shader
	LogInfo("Compiling shader: " << fragment_file_path);
	char const * FragmentSourcePointer = FragmentShaderCode.c_str();
	glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL);
	glCompileShader(FragmentShaderID);

	// Check Fragment Shader
	glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if ( InfoLogLength > 0 ){
		std::vector<char> FragmentShaderErrorMessage(InfoLogLength+1);
		glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
		LogInfo(&FragmentShaderErrorMessage[0]);
	}

	// Link the program
	LogInfo("Linking program");
	GLuint ProgramID = glCreateProgram();
	glAttachShader(ProgramID, VertexShaderID);
	glAttachShader(ProgramID, FragmentShaderID);
	glLinkProgram(ProgramID);

	// Check the program
	glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
	glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if ( InfoLogLength > 0 ){
		std::vector<char> ProgramErrorMessage(InfoLogLength+1);
		glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
		LogInfo(&ProgramErrorMessage[0]);
	}

	glDetachShader(ProgramID, VertexShaderID);
	glDetachShader(ProgramID, FragmentShaderID);

	glDeleteShader(VertexShaderID);
	glDeleteShader(FragmentShaderID);

	std::cout << std::flush;
	std::cerr << std::flush;

	return ProgramID;
}


class SimpleTriangleRenderer {

private:

	jobject renderer;
	jmethodID jARenderer_isAlive;


	GLuint program;
	GLuint rotID;
	GLfloat angle;
	GLuint vaID;

public:
	SimpleTriangleRenderer(jobject renderer) :
		renderer(renderer),
		ctx(nullptr) {

		JNIEnv* env = JNIHelper::GetJNIEnv(true);

		jclass jARenderer = env->FindClass("org/eclipse/fx/drift/samples/ARenderer");
		jARenderer_isAlive = env->GetMethodID(jARenderer, "isAlive", "()Z");

		jclass jChestRenderer = env->FindClass("org/eclipse/fx/drift/samples/SimpleTriangleRenderer");
		jmethodID jChestRenderer_getNativeSurfaceId = env->GetMethodID(jChestRenderer, "getNativeSurfaceId", "()J");

		long surfaceId = (long) env->CallLongMethod(renderer, jChestRenderer_getNativeSurfaceId);

		surface = DriftFX::Get()->GetSurface(surfaceId);

		LogDebug("surface = " << surface)
	}


	void prepare() {
		LogDebug("prepare");
		surface->Initialize();
		ctx = surface->GetContext();
		ctx->SetCurrent();
		LogDebug("sample glew init " << glewInit());

		glGenFramebuffers(1, &fb);


		program = LoadShaders( "/SimpleTriangleRenderer/Triangle.vertexshader", "/SimpleTriangleRenderer/Triangle.fragmentshader" );
		LogDebug("program: " << program);
		rotID = glGetUniformLocation(program, "rot");


		// vertex array
		glGenVertexArrays(1, &vaID);

		static const Vertex data2[] = {
			{  0.0f,   0.5f, 0.0f, {0.0f, 0.0f, 1.0f} },
			{  0.45f, -0.5f, 0.0f, {0.0f, 1.0f, 0.0f} },
			{ -0.45f, -0.5f, 0.0f, {1.0f, 0.0f, 0.0f} }
		};

		GLuint vboID;
		glGenBuffers(1, &vboID);
		glBindBuffer(GL_ARRAY_BUFFER, vboID);
		glBufferData(GL_ARRAY_BUFFER, sizeof(data2), data2, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		// build va
		glBindVertexArray(vaID);

		glBindBuffer(GL_ARRAY_BUFFER, vboID);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0 );

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) (3 * sizeof(GLfloat)) );

		glBindVertexArray(0);


//		glDisableVertexAttribArray(0);
//		glDisableVertexAttribArray(1);



		//GLERR();
		LogDebug("prepare done");


		angle = 0;

	}

	void cleanup() {

		glUseProgram(0);

		glDeleteVertexArrays(1, &vaID);

		glDeleteProgram(program);


		glDeleteFramebuffers(1, &fb);
		surface->Cleanup();
		LogDebug("cleanup finished.")
	}

	void renderFrame(GLuint textureId, int width, int height) {

		glBindFramebuffer(GL_FRAMEBUFFER, fb);
		glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, textureId, 0);

		checkFramebuffer();



		angle += 0.1f;


		glViewport(0, 0, width, height);

		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(program);
		glUniform1f(rotID, angle);

		// render
		glBindVertexArray(vaID);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);


		glFlush();


		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	void checkFramebuffer() {

		GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
		switch (status) {
		case GL_FRAMEBUFFER_COMPLETE: break;
		case GL_FRAMEBUFFER_UNDEFINED: LogError("GL_FRAMEBUFFER_UNDEFINED"); break;
		case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT: LogError("GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT"); break;
		case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT: LogError("GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT"); break;
		case GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER: LogError("GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER"); break;
		case GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER: LogError("GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER"); break;
		case GL_FRAMEBUFFER_UNSUPPORTED: LogError("GL_FRAMEBUFFER_UNSUPPORTED"); break;
		case GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE: LogError("GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE"); break;
		case GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS: LogError("GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS"); break;
		default: LogError("Unknown framebuffer issue " << status); break;
		}

	}

	void renderFrame() {
		///////////////
		// ACQUIRE CODE
		///////////////
		RenderTarget* acquired = surface->Acquire();
		////////////////

		if (acquired != nullptr) {
			renderFrame(acquired->GetGLTexture(), acquired->GetWidth(), acquired->GetHeight());
		}

		///////////////////////
		// PRESENT CODE
		///////////////////////
		surface->Present(acquired, CENTER);
	}

	void run() {
		JNIHelper::AttachThread();

		prepare();

		while (IsAlive()) {

			renderFrame();

			this_thread::sleep_for(milliseconds(1));
		}

		cleanup();

		JNIHelper::ReleaseThread();
	}

	DriftFXSurface *surface;
private:
	GLuint fb = 0;

	GLContext *ctx;

	bool IsAlive() {
		JNIEnv* env = JNIHelper::GetJNIEnv(true);
		jboolean isAlive = env->CallBooleanMethod(renderer, jARenderer_isAlive);
		return (bool) isAlive;
	}

};

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_samples_SimpleTriangleRenderer_nRun(JNIEnv *env, jclass cls, jobject renderer) {
	JavaVM* vm;
	env->GetJavaVM(&vm);
	JNIHelper::Initialize(vm);
	SimpleTriangleRenderer* nativeRenderer = new SimpleTriangleRenderer(renderer);
	nativeRenderer->run();
	delete nativeRenderer;
}

