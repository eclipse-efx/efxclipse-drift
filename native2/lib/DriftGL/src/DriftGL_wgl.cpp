#ifdef DRIFTGL_WGL
#include "DriftGL.h"
#include "DriftGL_wgl.h"

#include <iostream>

#pragma comment (lib, "opengl32.lib")

namespace driftgl {

	int WGL_DRAW_TO_WINDOW_ARB = 0x2001;
	int WGL_ACCELERATION_ARB = 0x2003;
	int WGL_SUPPORT_OPENGL_ARB = 0x2010;
	int WGL_DOUBLE_BUFFER_ARB = 0x2011;
	int WGL_PIXEL_TYPE_ARB = 0x2013;
	int WGL_COLOR_BITS_ARB = 0x2014;
	int WGL_DEPTH_BITS_ARB = 0x2022;
	int WGL_STENCIL_BITS_ARB = 0x2023;

	int WGL_FULL_ACCELERATION_ARB = 0x2027;
	int WGL_TYPE_RGBA_ARB = 0x202B;

	int WGL_CONTEXT_MAJOR_VERSION_ARB = 0x2091;
	int WGL_CONTEXT_MINOR_VERSION_ARB = 0x2092;
	int WGL_CONTEXT_PROFILE_MASK_ARB = 0x9126;

	int WGL_CONTEXT_CORE_PROFILE_BIT_ARB = 0x00000001;


	typedef HGLRC(APIENTRY * PFNWGLCREATECONTEXTATTRIBSARBPROC)(HDC hDC, HGLRC hShareContext, const int *attribList);
	typedef BOOL(APIENTRY * PFNWGLCHOOSEPIXELFORMATARBPROC)(HDC hDC, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int * piFormats, UINT *nNumFormats);
	static PFNWGLCREATECONTEXTATTRIBSARBPROC pfnWglCreateContextAttribsARB = 0;
	static PFNWGLCHOOSEPIXELFORMATARBPROC pfnWglChoosePixelFormatARB = 0;

	HGLRC wglCreateContextAttribsARB(HDC hDC, HGLRC hShareContext, const int *attribList) {
		return pfnWglCreateContextAttribsARB(hDC, hShareContext, attribList);
	}

	BOOL wglChoosePixelFormatARB(HDC hDC, const int *piAttribIList, const FLOAT *piAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats) {
		return pfnWglChoosePixelFormatARB(hDC, piAttribIList, piAttribFList, nMaxFormats, piFormats, nNumFormats);
	}

struct WGLContext : Context {
	HWND hWND;
	HDC hDC;
	HGLRC hGLRC;
};

ATOM registerClass(HINSTANCE hInstance) {

	WNDCLASSEX wcex;
	ZeroMemory(&wcex, sizeof(wcex));
	wcex.cbSize = sizeof(wcex);
	wcex.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wcex.lpfnWndProc = DefWindowProc;
	wcex.hInstance = hInstance;
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.lpszClassName = "DriftGLDummyWindow";

	return RegisterClassEx(&wcex);
}

HWND CreateDriftGLWindow(HINSTANCE hInstance) {
	return CreateWindow(
		"DriftGLDummyWindow", "DriftGL Dummy Window",      // window class, title
		WS_CLIPSIBLINGS | WS_CLIPCHILDREN, // style
		0, 0,                       // position x, y
		1, 1,                       // width, height
		NULL, NULL,                 // parent window, menu
		hInstance, NULL);           // instance, param
}

void SetupPixelFormat(HDC hDC) {
	int pixel_format_attribs[] = {
	WGL_SUPPORT_OPENGL_ARB,     GL_TRUE,
	WGL_ACCELERATION_ARB,       WGL_FULL_ACCELERATION_ARB,
	0
	};

	int pixel_format;
	UINT num_formats;
	wglChoosePixelFormatARB(hDC, pixel_format_attribs, 0, 1, &pixel_format, &num_formats);

	PIXELFORMATDESCRIPTOR pfd;
	DescribePixelFormat(hDC, pixel_format, sizeof(pfd), &pfd);
	BOOL result = SetPixelFormat(hDC, pixel_format, &pfd);
	std::cout << "SetPixelFormat: " << result << std::endl;
}



void Initialize() {
	HINSTANCE hInstance = NULL;
	ATOM cls = registerClass(hInstance);
	HWND window = CreateDriftGLWindow(hInstance);
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
	pfnWglChoosePixelFormatARB = (PFNWGLCHOOSEPIXELFORMATARBPROC) wglGetProcAddress("wglChoosePixelFormatARB");
	pfnWglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC) wglGetProcAddress("wglCreateContextAttribsARB");
	procs::Initialize([](const char* name) {
		PROC proc = wglGetProcAddress(name);
		//std::cout << " * " << name << ": " << proc << std::endl;
		if (proc == 0) {
			std::cout << " ! Could not acquire " << name << std::endl;
		}
		return (void*)proc;
	});
	//std::cout << "Initialze OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(dummyContext);
	ReleaseDC(window, hDC);
	DestroyWindow(window);
}

Context* CreateContext(Context* sharedContext, int majorHint, int minorHint) {
	//std::cout << "CreateContext" << std::endl << std::flush;
	WGLContext* sharedCtx = (WGLContext*)sharedContext;
	HGLRC shared = sharedCtx == nullptr ? nullptr : sharedCtx->hGLRC;
	WGLContext* ctx = new WGLContext();

	HINSTANCE hInstance = NULL;

	ctx->hWND = CreateDriftGLWindow(hInstance);
	//std::cout << " - hWND = " << ctx->hWND << std::endl;
	if (ctx->hWND == NULL) {
		// we failed to create the window
		delete ctx;
		return NULL;
	}
	ctx->hDC = GetDC(ctx->hWND);
	if (ctx->hDC == NULL) {
		// we failed to get the HDC
		DestroyWindow(ctx->hWND);
		delete ctx;
		return NULL;
	}
	//std::cout << " - hDC = " << ctx->hDC << std::endl;

	SetupPixelFormat(ctx->hDC);

	int attribList[] = {
		WGL_CONTEXT_MAJOR_VERSION_ARB, majorHint,
		WGL_CONTEXT_MINOR_VERSION_ARB, minorHint,
		WGL_CONTEXT_PROFILE_MASK_ARB,  WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
	0,
	};

	ctx->hGLRC = wglCreateContextAttribsARB(ctx->hDC, shared, attribList);
	//std::cout << " - hGLRC = " << ctx->hGLRC << std::endl << std::flush;

	// MakeContextCurrent(ctx);
	//	std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;

	if (ctx->hGLRC == NULL) {
		// we failed to create the context
		ReleaseDC(ctx->hWND, ctx->hDC);
		DestroyWindow(ctx->hWND);
		delete ctx;
		return NULL;
	}

	return ctx;
}

void DestroyContext(Context* context) {
	WGLContext* ctx = (WGLContext*)context;
	wglDeleteContext(ctx->hGLRC);
	ReleaseDC(GetDesktopWindow(), ctx->hDC);
	DestroyWindow(ctx->hWND);
	delete ctx;
}

bool MakeContextCurrent(Context* context) {
	WGLContext* ctx = (WGLContext*)context;
	if (ctx == nullptr) {
		return wglMakeCurrent(nullptr, nullptr);
	}
	else {
		return wglMakeCurrent(ctx->hDC, ctx->hGLRC);
	}
}

void* GetNativeContextHandle(Context* context) {
	WGLContext* ctx = (WGLContext*)context;
	return ctx->hGLRC;
}

}

#endif
