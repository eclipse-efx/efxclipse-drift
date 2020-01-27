
#include "gl_context.h"
#include <jni_md.h>
#include <jni.h>

using namespace driftfx::internal::gl;

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_GL_initialize(JNIEnv *env, jclass cls) {
	Initialize();
}

extern "C" JNIEXPORT jlong JNICALL Java_org_eclipse_fx_drift_internal_GL_createContext(JNIEnv *env, jclass cls, jlong sharedContext) {
	return (jlong)CreateContext((Context*) sharedContext);
}
extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_GL_destroyContext(JNIEnv *env, jclass cls, jlong context) {
	DestroyContext((Context*) context);
}
extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_GL_makeContextCurrent(JNIEnv *env, jclass cls, jlong context) {
	MakeContextCurrent((Context*) context);
}
