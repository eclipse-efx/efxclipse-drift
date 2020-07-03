
#include <minctx.h>

#include <GL/glew.h>
#include <GL/wglew.h>

#include <Windows.h>

#include <iostream>

#include <thread>




namespace minctx {
	struct WGLContext : Context {
		HWND hWND;
		HDC hDC;
		HGLRC hGLRC;
	};
}

bool clsReg = false;
ATOM cls;

ATOM registerClass(HINSTANCE hInstance) {

	WNDCLASSEX wcex;
	ZeroMemory(&wcex, sizeof(wcex));
	wcex.cbSize = sizeof(wcex);
	wcex.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wcex.lpfnWndProc = DefWindowProc;
	wcex.hInstance = hInstance;
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.lpszClassName = "minctxoffscreen";

	return RegisterClassEx(&wcex);
}

HWND CreateOffscreenWindow(HINSTANCE hInstance) {
	return CreateWindow(
		"minctxoffscreen", "minctx Offscreen Window",      // window class, title
		WS_CLIPSIBLINGS | WS_CLIPCHILDREN, // style
		0, 0,                       // position x, y
		1, 1,                       // width, height
		NULL, NULL,                 // parent window, menu
		hInstance, NULL);           // instance, param
}

bool initDone = false;

void shittyInit() {
	HINSTANCE hInstance = NULL;
	ATOM cls = registerClass(hInstance);
	HWND window = CreateOffscreenWindow(hInstance);
	HDC hDC = GetDC(window);
	PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    // Flags
		PFD_TYPE_RGBA,        // The kind of framebuffer. RGBA or palette.
		32,                   // Colordepth of the framebuffer.
		0, 0, 0, 0, 0, 0,
		0,
		0,
		0,
		0, 0, 0, 0,
		24,                   // Number of bits for the depthbuffer
		8,                    // Number of bits for the stencilbuffer
		0,                    // Number of Aux buffers in the framebuffer.
		PFD_MAIN_PLANE,
		0,
		0, 0, 0
	};
	int pf = ChoosePixelFormat(hDC, &pfd);
	SetPixelFormat(hDC, pf, &pfd);

	HGLRC dummyContext = wglCreateContext(hDC);
	BOOL c = wglMakeCurrent(hDC, dummyContext);

	GLenum res = glewInit();
	std::cout << "glewInit -> " << res << std::endl;
	GLenum wglewInitRes = wglewInit();
	std::cout << "wglewInit -> " << (GLEW_OK == wglewInitRes) << std::endl;

	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(dummyContext);
	ReleaseDC(window, hDC);
	DestroyWindow(window);

}

void SetupPixelFormat(HDC hDC) {
	int pixel_format_attribs[] = {
		WGL_SUPPORT_OPENGL_ARB,     GL_TRUE,
		WGL_ACCELERATION_ARB,       WGL_FULL_ACCELERATION_ARB,
		0
	};

	int pixel_format;
	UINT num_formats;
	std::cout << "calling wglChoosePixelFormatARB: " << wglChoosePixelFormatARB << std::endl;

	wglChoosePixelFormatARB(hDC, pixel_format_attribs, 0, 1, &pixel_format, &num_formats);

	PIXELFORMATDESCRIPTOR pfd;
	DescribePixelFormat(hDC, pixel_format, sizeof(pfd), &pfd);
	BOOL result = SetPixelFormat(hDC, pixel_format, &pfd);
	//std::cout << "SetPixelFormat: " << result << std::endl;
}


minctx::Context* minctx::CreateContext(minctx::Context* sharedContext, int majorHint, int minorHint) {
	std::cout << "CreateContext" << std::endl;

	if (!initDone) {
		std::thread init(shittyInit);
		init.join();
		initDone = true;
	}

	HINSTANCE hInstance = NULL;

	if (!clsReg) {
		cls = registerClass(hInstance);
	}


//	HGLRC shared = sharedCtx == nullptr ? nullptr : sharedCtx->hGLRC;
	HGLRC shared = nullptr;
	
	WGLContext* ctx = new WGLContext();
	
	int attribList[] = {
		WGL_CONTEXT_MAJOR_VERSION_ARB, majorHint,
		WGL_CONTEXT_MINOR_VERSION_ARB, minorHint,

		WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_DEBUG_BIT_ARB,
		// TODO compat vs core contexts
		WGL_CONTEXT_PROFILE_MASK_ARB,  WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB,
		0,
	};

	ctx->hWND = CreateOffscreenWindow(hInstance);
	std::cout << " - hWND = " << ctx->hWND << std::endl;
	if (ctx->hWND == NULL) {
		// we failed to create the window
		delete ctx;
		return NULL;
	}
	ctx->hDC = GetDC(ctx->hWND);
	std::cout << " - hDC = " << ctx->hDC << std::endl;
	if (ctx->hDC == NULL) {
		// we failed to get the HDC
		DestroyWindow(ctx->hWND);
		delete ctx;
		return NULL;
	}
	SetupPixelFormat(ctx->hDC);

	std::cout << "calling wglCreateContextAttribsARB: " << wglCreateContextAttribsARB << std::endl;
	ctx->hGLRC = wglCreateContextAttribsARB(ctx->hDC, shared, attribList);
	std::cout << " - hGLRC = " << ctx->hGLRC << std::endl;
	if (ctx->hGLRC == NULL) {
		// we failed to create the context
		ReleaseDC(ctx->hWND, ctx->hDC);
		DestroyWindow(ctx->hWND);
		delete ctx;
		return NULL;
	}

	return ctx;
}

void minctx::DestroyContext(minctx::Context* context) {
	minctx::WGLContext* ctx = (minctx::WGLContext*)context;
	wglDeleteContext(ctx->hGLRC);
	ReleaseDC(GetDesktopWindow(), ctx->hDC);
	DestroyWindow(ctx->hWND);
	delete ctx;
}

bool minctx::MakeContextCurrent(minctx::Context* context) {
	minctx::WGLContext* ctx = (minctx::WGLContext*)context;
	if (ctx == nullptr) {
		return wglMakeCurrent(nullptr, nullptr);
	}
	else {
		return wglMakeCurrent(ctx->hDC, ctx->hGLRC);
	}
}

bool minctx::IsContextCurrent(minctx::Context* context) {
	HGLRC currentContext = wglGetCurrentContext();
	minctx::WGLContext* ctx = (minctx::WGLContext*)context;
	return currentContext == ctx->hGLRC;
}

void* minctx::GetNativeContextHandle(minctx::Context* context) {
	minctx::WGLContext* ctx = (minctx::WGLContext*)context;
	return ctx->hGLRC;
}