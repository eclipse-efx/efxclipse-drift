
#include <jni.h>
#include <GL/glx.h>


//#include <GL/gl.h>

#include <utils/Logger.h>

#include "GLContext.h"

namespace gl {

typedef GLXContext (*glXCreateContextAttribsARBProc)(Display*, GLXFBConfig, GLXContext, Bool, const int*);
typedef Bool (*glXMakeContextCurrentARBProc)(Display*, GLXDrawable, GLXDrawable, GLXContext);

static Display* display = nullptr;

Context* CreateContext(Context* sharedContext) {
	LinuxContext* shared = (LinuxContext*) sharedContext;
	GLXContext sharedCtx = shared == nullptr ? nullptr : shared->context;
	LinuxContext* ctx = new LinuxContext();
	ctx->type = TYPE_LINUX;

	if (display == nullptr) {
		display = XOpenDisplay( NULL );
	}

	//glxewInit(display);
	static int visualAttribs[] = { None };
	int fbConfigsCount = 0;
	GLXFBConfig* fbConfigs = glXChooseFBConfig( display, DefaultScreen(display), visualAttribs, &fbConfigsCount );
	int context_attribs[] = {
				GLX_CONTEXT_MAJOR_VERSION_ARB, 4,
				GLX_CONTEXT_MINOR_VERSION_ARB, 1,
				GLX_CONTEXT_FLAGS_ARB, GLX_CONTEXT_DEBUG_BIT_ARB,
				GLX_CONTEXT_PROFILE_MASK_ARB, GLX_CONTEXT_CORE_PROFILE_BIT_ARB,
				None
		};
	glXCreateContextAttribsARBProc glXCreateContextAttribsARB = (glXCreateContextAttribsARBProc) glXGetProcAddress( (const GLubyte *) "glXCreateContextAttribsARB" );
	glXMakeContextCurrentARBProc glXMakeContextCurrentARB   = (glXMakeContextCurrentARBProc)   glXGetProcAddress( (const GLubyte *) "glXMakeContextCurrent"      );

	ctx->context = glXCreateContextAttribsARB( display, fbConfigs[0], sharedCtx, True, context_attribs);
	LogInfo("CTX: " << ctx->context);


	int pbufferAttribs[] = {
		GLX_PBUFFER_WIDTH,  32,
		GLX_PBUFFER_HEIGHT, 32,
		None
	};
	ctx->pBuffer = glXCreatePbuffer( display, fbConfigs[0], pbufferAttribs );

	XFree( fbConfigs );
	XSync( display, False );


	return ctx;
}

void DestroyContext(Context* context) {
	LinuxContext* ctx = (LinuxContext*) context;
	glXDestroyPbuffer(display, ctx->pBuffer);
	glXDestroyContext(display, ctx->context);
}

void MakeContextCurrent(Context* context) {
	LinuxContext* ctx = (LinuxContext*) context;
	Bool result = glXMakeContextCurrent(display, ctx->pBuffer, ctx->pBuffer, ctx->context);
	LogInfo("Made context current: " << result);

	//glewInit();

	LogInfo("Version: " << glGetString(GL_VERSION));
	LogInfo("Vendor: " << glGetString(GL_VENDOR));

	PFNGLGENFRAMEBUFFERSPROC glGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC) glXGetProcAddress((const GLubyte*)"glGenFramebuffers");
	PFNGLGENBUFFERSPROC glGenBuffers = (PFNGLGENBUFFERSPROC) glXGetProcAddress((const GLubyte*)"glGenBuffers");
	PFNGLDELETEFRAMEBUFFERSPROC glDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC) glXGetProcAddress((const GLubyte*)"glDeleteFrameBuffers");
	PFNGLDELETEBUFFERSPROC glDeleteBuffers = (PFNGLDELETEBUFFERSPROC) glXGetProcAddress((const GLubyte*)"glDeleteBuffers");


	LogInfo("glGenTextures " << (void*) glGenTextures);
	LogInfo("glGenBuffers " << (void*) glGenBuffers);
	LogInfo("glGenFramebuffers " << (void*) glGenFramebuffers);

	GLuint x = -1;
	glGenTextures(1, &x);
	LogInfo("texture: " << x);
	glDeleteTextures(1, &x);

	x = -1;
	glGenBuffers(1, &x);
	LogInfo("buffer: " << x);
	glDeleteBuffers(1, &x);

	x = -1;
	glGenFramebuffers(1, &x);
	LogInfo("framebuffer: " << x);
	glDeleteFramebuffers(1, &x);
}

}


extern "C" JNIEXPORT jlong JNICALL Java_org_eclipse_fx_drift_internal_GL_createContext(JNIEnv *env, jclass cls, jlong sharedContext) {
	return (jlong) gl::CreateContext((gl::Context*) sharedContext);
}
extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_GL_destroyContext(JNIEnv *env, jclass cls, jlong context) {
	gl::DestroyContext((gl::Context*) context);
}
extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_GL_makeContextCurrent(JNIEnv *env, jclass cls, jlong context) {
	gl::MakeContextCurrent((gl::Context*) context);
}
