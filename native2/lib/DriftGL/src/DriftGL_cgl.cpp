#ifdef DRIFTGL_CGL

#include <DriftGL.h>
#include <DriftGL_cgl.h>

#include <iostream>

#include <OpenGL/OpenGL.h>
#include <OpenGL/CGLContext.h>
#include <OpenGL/CGLTypes.h>
#include <OpenGL/CGLDevice.h>

#include <CoreFoundation/CoreFoundation.h>

namespace driftgl {

	struct CGLContext : Context {
		CGLContextObj contextObj;
	};
    
    void* cglGetProcAddress(const char* procName)
    {
        static CFBundleRef openGLBundle = NULL;

        if (openGLBundle == NULL)
        {
            openGLBundle = CFBundleGetBundleWithIdentifier(CFSTR("com.apple.opengl"));
        }

        CFStringRef functionName = CFStringCreateWithCString(NULL, procName, kCFStringEncodingASCII);

        void* function = CFBundleGetFunctionPointerForName(openGLBundle, functionName);

        CFRelease(functionName);

        return function;
    }
    bool initialized = false;

    bool Initialize() {

	 	procs::Initialize([](const char* name) {
			void* proc = cglGetProcAddress(name);
			if (proc == 0) {
				std::cout << " ! Could not acquire " << name << std::endl;
			}
			return (void*) proc;
		});

        return true;
    }
    bool Destroy() {
        return true;
    }

    CGLContextObj getNative(Context* ctx) {
        if (ctx == nullptr) {
            return nullptr;
        }
        return ((CGLContext*) ctx)->contextObj;
    }

    Context* CreateContext(Context* sharedContext, int majorHint, int minorHint) {
        auto ctx = new CGLContext();
        auto sharedCtxObj = getNative(sharedContext);
        CGLPixelFormatAttribute profile = (CGLPixelFormatAttribute) kCGLOGLPVersion_Legacy;
        if (majorHint == 4) {
            profile = (CGLPixelFormatAttribute) kCGLOGLPVersion_GL4_Core;
        }
        if (majorHint == 3) {
            profile = (CGLPixelFormatAttribute) kCGLOGLPVersion_GL3_Core;
        }
        if (majorHint == 3 && minorHint == 2) {
            profile = (CGLPixelFormatAttribute) kCGLOGLPVersion_3_2_Core;
        }
        CGLPixelFormatAttribute attributes[5] = {
            //kCGLPFAPBuffer,
            kCGLPFAAccelerated,
            kCGLPFAOpenGLProfile, 
            profile,
            (CGLPixelFormatAttribute) 0
        };
        GLint num;

        CGLPixelFormatObj pix;
        if (sharedCtxObj != 0) {
            pix = CGLGetPixelFormat(sharedCtxObj);
        }
        else {
            CGLChoosePixelFormat( attributes, &pix, &num );
        }
        CGLError error = CGLCreateContext( pix, sharedCtxObj, &ctx->contextObj );
        if (error) {
            std::cout << "CreateContext Error: " << error << std::endl;
        }
        CGLError r = CGLDestroyPixelFormat( pix );

        return ctx;
    }

    Context* CreateSharedCompatContext(Context* sharedContext) {
        auto ctx = new CGLContext();
        auto sharedCtxObj = getNative(sharedContext);
        CGLPixelFormatAttribute attributes[5] = {
            //kCGLPFAPBuffer,
            kCGLPFAAccelerated,
            kCGLPFAOpenGLProfile,
            (CGLPixelFormatAttribute) kCGLOGLPVersion_Legacy,
            (CGLPixelFormatAttribute) 0
        };
        GLint num;

        CGLPixelFormatObj pix;
        CGLChoosePixelFormat( attributes, &pix, &num );
        std::cout << "calling CGLCreateContext(" << pix << ", " << sharedCtxObj << ")" << std::endl << std::flush;
        CGLError error = CGLCreateContext( pix, sharedCtxObj, &ctx->contextObj );
        if (error) {
            std::cout << "CreateSharedContext Error: " << error << std::endl;
        }
        std::cout << " => " << ctx->contextObj << std::endl << std::flush;
        CGLError r = CGLDestroyPixelFormat( pix );

        return ctx;
    }

    Context* WrapContext(long long nativeContextHandle) {
        auto ctx = new CGLContext();
        ctx->contextObj = (CGLContextObj) nativeContextHandle;
        return ctx;
    }

    void DestroyContext(Context* context) {
        auto ctx = (CGLContext*) context;
        CGLError result = CGLDestroyContext(ctx->contextObj);
        delete ctx;
    }

    bool MakeContextCurrent(Context* context) {
        auto ctxObj = getNative(context);
        CGLError result = CGLSetCurrentContext(ctxObj);
        std::cout << "currentContext = " << CGLGetCurrentContext() << std::endl;
        std::cout << "CGLSetCurrentContext("<< ctxObj <<") returned " << result << std::endl;

        std::cout << "currentContext = " << CGLGetCurrentContext() << std::endl;

        return true;
    }

    bool IsContextCurrent(Context* context) {
        CGLContext* ctx = (CGLContext*) context;
        return CGLGetCurrentContext() == ctx->contextObj;
    }

    void* GetNativeContextHandle(Context* context) {
        CGLContext* ctx = (CGLContext*) context;
        return (void*) ctx->contextObj;
    }

    Context* GetCurrentContext() {

        return 0;
    }
}


#endif
