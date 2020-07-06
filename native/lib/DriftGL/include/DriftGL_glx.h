#ifdef DRIFTGL_GLX

#ifndef DRIFTGL_GLX_H_
#define DRIFTGL_GLX_H_

#include <X11/Xlib.h>
#include <GL/glx.h>

namespace driftgl {

	extern Display* display;

	typedef GLXContext (*glXCreateContextAttribsARBProc)(Display*, GLXFBConfig, GLXContext, Bool, const int*);
	typedef Bool (*glXMakeContextCurrentARBProc)(Display*, GLXDrawable, GLXDrawable, GLXContext);

	extern glXCreateContextAttribsARBProc glXCreateContextAttribsARB;
	extern glXMakeContextCurrentARBProc glXMakeContextCurrentARB;



}

#endif


#endif
