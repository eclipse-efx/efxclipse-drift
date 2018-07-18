#ifndef JNINATIVESURFACE_H_
#define JNINATIVESURFACE_H_

#include <jni.h>
#include "SharedTexture.h"

namespace driftfx {
namespace internal {

class JNINativeSurface {

public:
	JNINativeSurface(jobject javaNativeSurface);
	virtual ~JNINativeSurface();


	void Present(FrameData frameData);

	static void Initialize();

private:

	jobject jNativeSurfaceInstance;

	static jclass jNativeSurfaceClass;
	static jmethodID jNativeSurface_AcquireMethod;
	static jmethodID jNativeSurface_PresentMethod;
	static jmethodID jNativeSurface_Present2Method;
	static jmethodID jNativeSurface_Present3Method;

	static jclass jFrameDataClass;
	static jfieldID jFrameData_d3dShareHandleField;
	static jfieldID jFrameData_widthField;
	static jfieldID jFrameData_heightField;

	static jmethodID jFrameData_constructor;

};

}
}


#endif /* JNINATIVESURFACE_H_ */
