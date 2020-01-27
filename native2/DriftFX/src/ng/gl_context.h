

#ifndef NG_GLCONTEXT_H_
#define NG_GLCONTEXT_H_

#include <windows.h>

#include "gl_context_procs.h"


#define WGL // TODO



namespace driftfx{
namespace internal{
namespace gl {

	typedef void GLvoid;
	typedef unsigned int GLenum;
	typedef float GLfloat;
	typedef int GLint;
	typedef int GLsizei;
	typedef unsigned int GLbitfield;
	typedef double GLdouble;
	typedef unsigned int GLuint;
	typedef unsigned char GLboolean;
	typedef unsigned char GLubyte;

	namespace procs {
		typedef void (* PFNGLGENTEXTURESPROC) (GLsizei n, GLuint *textures);
		typedef void (* PFNGLDELETETEXTURESPROC) (GLsizei n, const GLuint *textures);
		typedef GLboolean(* PFNGLISTEXTUREPROC) (GLuint texture);

		typedef void (* PFNGLGENFRAMEBUFFERSPROC) (GLsizei n, GLuint *framebuffers);
		typedef void (* PFNGLDELETEFRAMEBUFFERSPROC) (GLsizei n, const GLuint *framebuffers);
		typedef GLboolean(* PFNGLISFRAMEBUFFERPROC) (GLuint framebuffer);


		typedef void* (LookupFunctionPointer(const char* functionName));
		void Initialize(LookupFunctionPointer lookupFunctionPointer);
	}

	void glGenTextures(GLsizei n, GLuint *textures);
	void glDeleteTextures(GLsizei n, const GLuint *textures);
	GLboolean glIsTexture(GLuint texture);

	void glGenFramebuffers(GLsizei n, GLuint *textures);
	void glDeleteFramebuffers(GLsizei n, GLuint *textures);
	GLboolean glIsFramebuffer(GLuint framebuffer);

	



struct Context {
	int type;
};

#ifdef GLX
#include <GL/glx.h>
struct LinuxContext : public Context {
	GLXContext context;
	GLXPbuffer pBuffer;
};
#endif // LINUX

#ifdef WGL
//#include <wingdi.h>
struct WGLContext : public Context {
	HWND hWND;
	HDC hDC;
	HGLRC hGLRC;
};
#endif // WIN32

const int TYPE_LINUX = 0;
const int TYPE_WGL = 1;




void Initialize();

Context* CreateContext(Context* sharedContext);

void DestroyContext(Context* context);

void MakeContextCurrent(Context* context);

}
}
}

#endif // NG_GLCONTEXT_H_
