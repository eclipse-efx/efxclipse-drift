#ifndef _CGL_H
#define _CGL_H

#include <OpenGL/CGLTypes.h>
#include <IOSurface/IOSurface.h>
#include <string>


void checkErr(CGLError cglError, std::string msg);

extern "C" void* getCGLContextObj(void* nsJContext);
extern "C" IOSurfaceRef createIOSurface(int width, int height);
extern "C" void releaseIOSurface(IOSurfaceRef ioSurface);

#endif
