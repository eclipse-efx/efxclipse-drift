
#include "gl_context.h"



namespace driftfx {
	namespace internal {
		namespace gl {
			namespace procs {
				PFNGLGENTEXTURESPROC pfnGlGenTextures;
				PFNGLDELETETEXTURESPROC pfnGlDeleteTextures;
				PFNGLISTEXTUREPROC pfnGLIsTexture;

				PFNGLGENFRAMEBUFFERSPROC pfnGlGenFramebuffers;
				PFNGLDELETEFRAMEBUFFERSPROC pfnGlDeleteFramebuffers;
				PFNGLISFRAMEBUFFERPROC pfnGlIsFramebuffer;

				void Initialize(LookupFunctionPointer lookupFunctionPointer) {
					pfnGlGenTextures = (PFNGLGENTEXTURESPROC)lookupFunctionPointer("glGenTextures");
					pfnGlDeleteTextures = (PFNGLDELETETEXTURESPROC)lookupFunctionPointer("glDeleteTextures");
					pfnGLIsTexture = (PFNGLISTEXTUREPROC)lookupFunctionPointer("glIsTexture");

					pfnGlGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC)lookupFunctionPointer("glGenFramebuffers");
					pfnGlDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC)lookupFunctionPointer("glDeleteFramebuffers");
					pfnGlIsFramebuffer = (PFNGLISFRAMEBUFFERPROC)lookupFunctionPointer("glIsFramebuffer");
				}
			}

			void glGenTextures(GLsizei n, GLuint *textures) {
				procs::pfnGlGenTextures(n, textures);
			}
			void glDeleteTextures(GLsizei n, const GLuint *textures) {
				procs::pfnGlDeleteTextures(n, textures);
			}
			GLboolean glIsTexture(const GLuint texture) {
				return procs::pfnGLIsTexture(texture);
			}

			void glGenFramebuffers(GLsizei n, GLuint *framebuffers) {
				procs::pfnGlGenFramebuffers(n, framebuffers);
			}
			void glDeleteFramebuffers(GLsizei n, const GLuint *framebuffers) {
				procs::pfnGlDeleteFramebuffers(n, framebuffers);
			}
			GLboolean glIsFramebuffer(const GLuint framebuffer) {
				return procs::pfnGlIsFramebuffer(framebuffer);
			}
		}
	}
}




