
#include "gl_context.h"
#include <windows.h>
//#include <jni.h>
//#include <jni_md.h>
#include <GL/GL.h>
#pragma comment (lib, "opengl32.lib")

#include <iostream>

// See https://www.opengl.org/registry/specs/ARB/wgl_pixel_format.txt for all values
#define WGL_DRAW_TO_WINDOW_ARB                    0x2001
#define WGL_ACCELERATION_ARB                      0x2003
#define WGL_SUPPORT_OPENGL_ARB                    0x2010
#define WGL_DOUBLE_BUFFER_ARB                     0x2011
#define WGL_PIXEL_TYPE_ARB                        0x2013
#define WGL_COLOR_BITS_ARB                        0x2014
#define WGL_DEPTH_BITS_ARB                        0x2022
#define WGL_STENCIL_BITS_ARB                      0x2023

#define WGL_FULL_ACCELERATION_ARB                 0x2027
#define WGL_TYPE_RGBA_ARB                         0x202B

// See https://www.opengl.org/registry/specs/ARB/wgl_create_context.txt for all values
#define WGL_CONTEXT_MAJOR_VERSION_ARB             0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB             0x2092
#define WGL_CONTEXT_PROFILE_MASK_ARB              0x9126

#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB          0x00000001

namespace driftfx {namespace internal {
namespace gl {
	typedef HGLRC(APIENTRY * PFNWGLCREATECONTEXTATTRIBSARBPROC)(HDC hDC, HGLRC hShareContext, const int *attribList);
	static PFNWGLCREATECONTEXTATTRIBSARBPROC pfnCreateContextAttribsARB = 0;


	HGLRC wglCreateContextAttribsARB(HDC hDC, HGLRC hshareContext, const int *attribList) {
		return pfnCreateContextAttribsARB(hDC, hshareContext, attribList);
	}

	typedef BOOL WINAPI wglChoosePixelFormatARB_type(HDC hdc, const int *piAttribIList,
		const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
	wglChoosePixelFormatARB_type *wglChoosePixelFormatARB;

	LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

		switch (message) {
		case WM_KEYDOWN:
if (wParam == VK_ESCAPE) {
	PostQuitMessage(0);
}
break;
		case WM_CLOSE:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		return 0;       // message handled
	}

	ATOM registerClass(HINSTANCE hInstance) {

		WNDCLASSEX wcex;
		ZeroMemory(&wcex, sizeof(wcex));
		wcex.cbSize = sizeof(wcex);
		wcex.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		wcex.lpfnWndProc = WindowProcedure;
		wcex.hInstance = hInstance;
		wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
		wcex.lpszClassName = "DriftWindow";

		return RegisterClassEx(&wcex);
	}

	HWND CreateDriftWindow(HINSTANCE hInstance) {
		return CreateWindow(
			"DriftWindow", "Fake Window",      // window class, title
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
		std::cout << " - num_formats = " << num_formats << std::endl;

		PIXELFORMATDESCRIPTOR pfd;
		DescribePixelFormat(hDC, pixel_format, sizeof(pfd), &pfd);
		SetPixelFormat(hDC, pixel_format, &pfd);
	}

	void Initialize() {
		std::cout << "Initialize" << std::endl;

		HINSTANCE hInstance = NULL; // GetModuleHandle(NULL);
		std::cout << " - hInstance = " << hInstance << std::endl;

		ATOM cls = registerClass(hInstance);

		HWND window = CreateDriftWindow(hInstance);

		std::cout << " - window = " << window << std::endl;
		HDC hDC = GetDC(window);
		std::cout << " - hDC = " << hDC << std::endl;

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
		std::cout << " - dummyContext = " << dummyContext << std::endl;
		BOOL c = wglMakeCurrent(hDC, dummyContext);
		std::cout << " - made current = " << c << std::endl;

		std::cout << " OpenGL " << glGetString(GL_VERSION) << std::endl;

		std::cout << " looking up function pointers" << std::endl;

		procs::Initialize([](const char* name) {
			PROC proc = wglGetProcAddress(name);
			std::cout << " * " << name << ": " << proc << std::endl;
			return (void*) proc;
		});

		std::cout << " done." << std::endl;


		pfnCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB");
		std::cout << " - got function pointer pfnCreateContextAttribsARB = " << pfnCreateContextAttribsARB << std::endl << std::flush;

		wglChoosePixelFormatARB = (wglChoosePixelFormatARB_type*)wglGetProcAddress(
			"wglChoosePixelFormatARB");
		std::cout << " - got function pointer wglChoosePixelFormatARB = " << wglChoosePixelFormatARB << std::endl << std::flush;

		wglMakeCurrent(NULL, NULL);
		wglDeleteContext(dummyContext);
		ReleaseDC(window, hDC);

		DestroyWindow(window);
		//UnregisterClass("Core", hInstance);
	}

	Context* CreateContext(Context* sharedContext) {
		std::cout << "CreateContext" << std::endl << std::flush;
		WGLContext* sharedCtx = (WGLContext*)sharedContext;
		HGLRC shared = sharedCtx == nullptr ? nullptr : sharedCtx->hGLRC;
		WGLContext* ctx = new WGLContext();

		HINSTANCE hInstance = NULL;

		ctx->hWND = CreateDriftWindow(hInstance);
		ctx->hDC = GetDC(ctx->hWND);

		std::cout << " - hDC = " << ctx->hDC << std::endl;
		
		SetupPixelFormat(ctx->hDC);
		
		int attribList[] = {
		WGL_CONTEXT_MAJOR_VERSION_ARB, 4,
		WGL_CONTEXT_MINOR_VERSION_ARB, 6,
		WGL_CONTEXT_PROFILE_MASK_ARB,  WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
		0,
		};

		ctx->hGLRC = wglCreateContextAttribsARB(ctx->hDC, shared, attribList);
		std::cout << " - hGLRC = " << ctx->hGLRC << std::endl << std::flush;

	//	MakeContextCurrent(ctx);
	//	std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;

		return ctx;
	}

	void DestroyContext(Context* context) {
		WGLContext* ctx = (WGLContext*) context;
		wglDeleteContext(ctx->hGLRC);
		ReleaseDC(GetDesktopWindow(), ctx->hDC);
		DestroyWindow(ctx->hWND);
		delete ctx;
	}

	void MakeContextCurrent(Context* context) {
		WGLContext* ctx = (WGLContext*) context;
		if (ctx == nullptr) {
			wglMakeCurrent(nullptr, nullptr);
		}
		else {
			wglMakeCurrent(ctx->hDC, ctx->hGLRC);
		}
	}

}
}
}