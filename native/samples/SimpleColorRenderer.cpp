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

using namespace std;
using namespace chrono;

using namespace driftfx;
using namespace driftfx::gl;

class SimpleColorRenderer {

private:

	jobject renderer;
	jmethodID jARenderer_isAlive;

public:
	SimpleColorRenderer(jobject renderer) :
		renderer(renderer),
		ctx(nullptr) {

		JNIEnv* env = JNIHelper::GetJNIEnv(true);

		jclass jARenderer = env->FindClass("org/eclipse/fx/drift/samples/ARenderer");
		jARenderer_isAlive = env->GetMethodID(jARenderer, "isAlive", "()Z");

		jclass jChestRenderer = env->FindClass("org/eclipse/fx/drift/samples/SimpleColorRenderer");
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
		LogDebug("prepare done");
	}

	void cleanup() {
		glDeleteFramebuffers(1, &fb);
		surface->Cleanup();
		LogDebug("cleanup finished.")
	}

	float pow = 0;

	void interpolate(float d, float r0, float g0, float b0, float r1, float g1, float b1, float &r, float &g, float &b) {
		r = r0 * d + r1 * (1-d);
		g = g0 * d + g1 * (1-d);
		b = b0 * d + b1 * (1-d);
	}

	float red0 = 0.f, green0 = 0.5f, blue0 = 0.7f;
	float red1 = 1.f, green1 = 1.f, blue1 = 0.f;

	void sw(float &a, float &b) {
		float t = a;
		a = b;
		b = t;
	}

	void renderFrame(GLuint textureId, int width, int height) {
		pow += 0.01f;
		if (pow > 1) {
			pow -= 1;
			sw(red0, red1);
			sw(green0, green1);
			sw(blue0, blue1);
		}

		float red; float green; float blue;
		interpolate(pow, red0, green0, blue0, red1, green1, blue1, red, green, blue);

		glBindFramebuffer(GL_FRAMEBUFFER, fb);
		glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, textureId, 0);

		checkFramebuffer();

		glClearColor(red, green, blue, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		glEnable(GL_SCISSOR_TEST);
		glScissor(10, 10, 50, 50);
		glViewport(10, 10, 50, 50);
		glClearColor(1, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		glScissor(70, 10, 50, 50);
		glViewport(10, 10, 50, 50);
		glClearColor(0, 1, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		glScissor(130, 10, 50, 50);
		glViewport(10, 10, 50, 50);
		glClearColor(0, 0, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		glDisable(GL_SCISSOR_TEST);

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

		unsigned int width = surface->GetWidth();
		unsigned int height = surface->GetHeight();



		RenderTarget* acquired = surface->Acquire(width, height);
		////////////////


		if (acquired != nullptr) {
			renderFrame(acquired->GetGLTexture(), width, height);
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

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_samples_SimpleColorRenderer_nRun(JNIEnv *env, jclass cls, jobject renderer) {
	JavaVM* vm;
	env->GetJavaVM(&vm);
	JNIHelper::Initialize(vm);
	SimpleColorRenderer* nativeRenderer = new SimpleColorRenderer(renderer);
	nativeRenderer->run();
	delete nativeRenderer;
}

