#ifndef SHAREDSURFACE_WIN32_WGLCONTEXT_H_
#define SHAREDSURFACE_WIN32_WGLCONTEXT_H_

#include <GL/glew.h>
#include <GL/wglew.h>

#include <DriftFX/GL/GLContext.h>
#include <DriftFX/Texture.h>

namespace driftfx {
using namespace gl;
namespace internal {
namespace gl {
namespace wgl {


class WGLGLContext : public GLContext {

public:
	WGLGLContext();
	WGLGLContext(WGLGLContext *shared);

	virtual ~WGLGLContext();
	virtual void SetCurrent();
	virtual void UnsetCurrent();

	virtual HGLRC GetHandle();

	virtual GLContext* CreateSharedContext();

private:
	WGLGLContext *shared;

	HWND hWnd;
	HDC hDC;
	HGLRC hGLRC;
	HPALETTE hPalette;

	void createGL(HWND hWnd);
	void destroyGL(HWND hWnd);
	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

}
}
}
}


#endif /* SHAREDSURFACE_WIN32_WGLCONTEXT_H_ */
