#ifdef DRIFTGL_WGL

#ifndef DRIFTGL_WGL_H_
#define DRIFTGL_WGL_H_

#include "Export.h"
#include <windows.h>

#include "DriftGL_gen.h"

namespace driftgl {

	extern int WGL_DRAW_TO_WINDOW_ARB;
	extern int WGL_ACCELERATION_ARB;
	extern int WGL_SUPPORT_OPENGL_ARB;
	extern int WGL_DOUBLE_BUFFER_ARB;
	extern int WGL_PIXEL_TYPE_ARB;
	extern int WGL_COLOR_BITS_ARB;
	extern int WGL_DEPTH_BITS_ARB;
	extern int WGL_STENCIL_BITS_ARB;

	extern int WGL_FULL_ACCELERATION_ARB;
	extern int WGL_TYPE_RGBA_ARB;

	extern int WGL_CONTEXT_MAJOR_VERSION_ARB;
	extern int WGL_CONTEXT_MINOR_VERSION_ARB;
	extern int WGL_CONTEXT_PROFILE_MASK_ARB;

	extern int WGL_CONTEXT_CORE_PROFILE_BIT_ARB;

	HGLRC wglCreateContextAttribsARB(HDC hDC, HGLRC hshareContext, const int *attribList);
	BOOL wglChoosePixelFormatARB(HDC hDC, const int *piAttribList);


	DRIFTGL_EXPORT HANDLE wglDXOpenDeviceNV(void* dxDevice);
	DRIFTGL_EXPORT bool wglDXCloseDeviceNV(HANDLE hDevice);
	DRIFTGL_EXPORT HANDLE wglDXRegisterObjectNV(HANDLE hDevice, void* dxObject, GLuint name, GLenum type, GLenum access);
	DRIFTGL_EXPORT bool wglDXUnregisterObjectNV(HANDLE hDevice, HANDLE hObject);
	DRIFTGL_EXPORT bool wglDXObjectAccess(HANDLE hObject, GLenum access);
	DRIFTGL_EXPORT bool wglDXLockObjectsNV(HANDLE hDevice, GLint count, HANDLE* hObjects);
	DRIFTGL_EXPORT bool wglDXUnlockObjectsNV(HANDLE hDevice, GLint count, HANDLE* hObjects);
	DRIFTGL_EXPORT bool wglDXSetResourceShareHandleNV(void* dxObject, HANDLE shareHandle);
}

#endif

#endif
