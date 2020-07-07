#ifdef DRIFTGL_GLX

#include <DriftGL.h>
#include <DriftGL_glx.h>

#include <X11/Xlib.h>
#include <GL/glx.h>

#include <iostream>

namespace driftgl {

	struct DriftGLXContext : Context {
		GLXContext glxContext;
		GLXPbuffer pBuffer;
	};

	Display* display;
	glXCreateContextAttribsARBProc glXCreateContextAttribsARB;
	glXMakeContextCurrentARBProc glXMakeContextCurrentARB;


	bool initialized = false;


	bool Initialize() {
		if (initialized) {
			return true;
		}
		std::cout << "driftgl::Initialize()" << std::endl;
		display = XOpenDisplay( NULL );

		if (!display) {
			// failed to open display
			std::cout << "Failed to open display" << std::endl;
			return false;
		}

		int glxMajor, glxMinor;

		if (!glXQueryVersion(display, &glxMajor, &glxMinor)) {
			// failed to query glx version
			std::cout << "Failed to query glx version!" << std::endl;
			return false;
		}
		std::cout << "GLX Version: " << glxMajor << "." << glxMinor << std::endl;

		procs::Initialize([](const char* name) {
			__GLXextFuncPtr proc = glXGetProcAddressARB((const GLubyte*) name);
			if (proc == 0) {
				std::cout << " ! Could not acquire " << name << std::endl;
			}
			return (void*) proc;
		});
		glXCreateContextAttribsARB = (glXCreateContextAttribsARBProc) glXGetProcAddressARB( (const GLubyte *) "glXCreateContextAttribsARB" );
		glXMakeContextCurrentARB   = (glXMakeContextCurrentARBProc)   glXGetProcAddressARB( (const GLubyte *) "glXMakeContextCurrent"      );


		std::cout << "driftgl::Initialize() End" << std::endl;
		initialized = true;
		return true;
	}

	bool Destroy() {
		XCloseDisplay(display);

		return true;
	}

	Context* CreateContext(Context* sharedContext, int majorHint, int minorHint) {
		std::cout << "driftgl::CreateContext( "<<sharedContext << ", " << majorHint << ", " << minorHint <<" )" << std::endl;
		DriftGLXContext* ctx = new DriftGLXContext();

		static int visualAttribs[] = { None };
		int fbConfigsCount = 0;
		std::cout << "calling glXChooseFbConfig " << glXChooseFBConfig << std::endl;
		GLXFBConfig* fbConfigs = glXChooseFBConfig( display, DefaultScreen(display), visualAttribs, &fbConfigsCount );

		std::cout << "Created fbConfigs = " << fbConfigs << std::endl;

		int context_attribs[] = {
				GLX_CONTEXT_MAJOR_VERSION_ARB, majorHint,
				GLX_CONTEXT_MINOR_VERSION_ARB, minorHint,
				GLX_CONTEXT_FLAGS_ARB, GLX_CONTEXT_DEBUG_BIT_ARB,
				GLX_CONTEXT_PROFILE_MASK_ARB, GLX_CONTEXT_CORE_PROFILE_BIT_ARB,
				None
		};

		DriftGLXContext* shared = (DriftGLXContext*) (sharedContext);
		GLXContext s = shared == NULL ? NULL : shared->glxContext;

		ctx->glxContext = glXCreateContextAttribsARB( display, fbConfigs[0], s, True, context_attribs);
		std::cout << "Created context = " << ctx->glxContext << std::endl;

		int pbufferAttribs[] = {
			GLX_PBUFFER_WIDTH,  32,
			GLX_PBUFFER_HEIGHT, 32,
			None
		};
		ctx->pBuffer = glXCreatePbuffer( display, fbConfigs[0], pbufferAttribs );
		std::cout << "Created pBuffer = " << ctx->pBuffer << std::endl;

		// clean up:
		XFree( fbConfigs );
		XSync( display, False );


		std::cout << "driftgl::CreateContext() End" << std::endl;
		return ctx;
	}

	Context* CreateSharedCompatContext(Context* sharedContext) {
			std::cout << "driftgl::CreateSharedCompatContext( "<<sharedContext << " )" << std::endl;
			DriftGLXContext* ctx = new DriftGLXContext();

			static int visualAttribs[] = { None };
			int fbConfigsCount = 0;
			std::cout << "calling glXChooseFbConfig " << glXChooseFBConfig << std::endl;
			GLXFBConfig* fbConfigs = glXChooseFBConfig( display, DefaultScreen(display), visualAttribs, &fbConfigsCount );

			std::cout << "Created fbConfigs = " << fbConfigs << std::endl;

			int context_attribs[] = {
					GLX_CONTEXT_MAJOR_VERSION_ARB, 2,
					GLX_CONTEXT_MINOR_VERSION_ARB, 1,
					GLX_CONTEXT_FLAGS_ARB, GLX_CONTEXT_DEBUG_BIT_ARB,
					GLX_CONTEXT_PROFILE_MASK_ARB, GLX_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB,
					None
			};

			DriftGLXContext* shared = (DriftGLXContext*) (sharedContext);
			GLXContext s = shared == NULL ? NULL : shared->glxContext;

			ctx->glxContext = glXCreateContextAttribsARB( display, fbConfigs[0], s, True, context_attribs);
			std::cout << "Created context = " << ctx->glxContext << std::endl;

			int pbufferAttribs[] = {
				GLX_PBUFFER_WIDTH,  32,
				GLX_PBUFFER_HEIGHT, 32,
				None
			};
			ctx->pBuffer = glXCreatePbuffer( display, fbConfigs[0], pbufferAttribs );
			std::cout << "Created pBuffer = " << ctx->pBuffer << std::endl;

			// clean up:
			XFree( fbConfigs );
			XSync( display, False );


			std::cout << "driftgl::CreateContext() End" << std::endl;
			return ctx;
		}

	Context* WrapContext(long long nativeContextHandle) {
		DriftGLXContext* ctx = new DriftGLXContext();
		ctx->glxContext = (GLXContext) nativeContextHandle;
		return ctx;
	}

	void DestroyContext(Context* context) {
		DriftGLXContext* ctx = (DriftGLXContext*) context;
		glXDestroyPbuffer(display, ctx->pBuffer);
		glXDestroyContext(display, ctx->glxContext);

		delete ctx;
	}

	bool MakeContextCurrent(Context* context) {
		DriftGLXContext* ctx = (DriftGLXContext*) context;
		return glXMakeContextCurrent(display, ctx->pBuffer, ctx->pBuffer, ctx->glxContext);
	}

	bool IsContextCurrent(Context* context) {
		GLXContext currentContext = glXGetCurrentContext();
		DriftGLXContext* ctx = (DriftGLXContext*) context;
		return currentContext == ctx->glxContext;
	}

}

#endif
