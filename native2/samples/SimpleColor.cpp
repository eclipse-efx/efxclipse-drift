
#include <jni.h>
#include <GL/glew.h>

//#include <GL/glx.h>

#include <utils/Logger.h>


float red0 = 0.f, green0 = 0.5f, blue0 = 0.7f;
float red1 = 1.f, green1 = 1.f, blue1 = 0.f;

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

	if (status == 0) {
		LogError("Error: " << glGetError());
	}

}

void interpolate(float d, float r0, float g0, float b0, float r1, float g1, float b1, float &r, float &g, float &b) {
	r = r0 * d + r1 * (1-d);
	g = g0 * d + g1 * (1-d);
	b = b0 * d + b1 * (1-d);
}

void sw(float &a, float &b) {
	float t = a;
	a = b;
	b = t;
}

float val = 0;

void renderFrame(GLuint textureId) {

	LogInfo("renderFrame glGenFramebuffers " << (void*)glGenFramebuffers);

	GLuint fb;
	glGenFramebuffers(1, &fb);

	if (!glIsFramebuffer(fb)) {
		//glGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC) glXGetProcAddress((const GLubyte*)"glGenFramebuffers");

		//LogInfo("Version: " << glGetString(GL_VERSION));
		//LogInfo("Vendor: " << glGetString(GL_VENDOR));

		//void* myaddr = (void*) glXGetProcAddress((const GLubyte*)"glGenFramebuffers");
		//LogInfo("-> " << myaddr);

		//GLuint fu = -123;
		//((void (*) (GLsizei, GLuint*)) myaddr)(1, &fu);
		//LogInfo("fu = " << fu);
		//glGenBuffers(1, &fu);
		//LogInfo("fu = " << fu);
		//glGenTextures(1, &fu);
		//LogInfo("fu = " << fu);

		
		//glewInit();

		GLuint x;
		glGenFramebuffers(1, &x);
		fb = x;

		GLuint what;
		glGenFramebuffers(1, &what);
		LogInfo("err " << glGetError())
		LogInfo("what " << what);
	}
	val += 0.01f;
	if (val > 1) {
		val -= 1;
		sw(red0, red1);
		sw(green0, green1);
		sw(blue0, blue1);
	}
	float red; float green; float blue;
	interpolate(val, red0, green0, blue0, red1, green1, blue1, red, green, blue);

	glBindFramebuffer(GL_FRAMEBUFFER, fb);
	glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, textureId, 0);
	LogInfo("fb = " << fb << " texId = " << textureId);
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

	glDeleteFramebuffers(1, &fb);
}
extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_samples_ng_SimpleColorSample_nRenderFrame(JNIEnv *env, jclass cls, jint tex) {
	renderFrame((GLuint) tex);
}
