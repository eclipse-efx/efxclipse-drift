#import <Cocoa/Cocoa.h>
#import <OpenGL/OpenGL.h>
#import <IOSurface/IOSurface.h>

void *getCGLContextObj(void *nsJContext) {
	NSOpenGLContext *nsContext = (NSOpenGLContext *) nsJContext;
	return (void *) nsContext.CGLContextObj;
}
