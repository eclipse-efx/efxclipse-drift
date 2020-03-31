#include <jni.h>
#include <iostream>
#include <iomanip>
                                //      org.eclipse.fx.drift.internal.jni.MemoryStack.nGetBufferAddress
extern "C" JNIEXPORT jlong JNICALL Java_org_eclipse_fx_drift_internal_jni_MemoryStack_nGetBufferAddress(JNIEnv* env, jclass cls, jobject buffer) {
    return (jlong) env->GetDirectBufferAddress(buffer);
}


extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_jni_MemoryStack_nSetLong(JNIEnv* env, jclass cls, jlong pTarget, jlong value) {
    long long* target = (long long*) pTarget;
    (*target) = (long long) value;
}
extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_internal_jni_MemoryStack_nOutputLong(JNIEnv* env, jclass cls, jlong pTarget) {
    long long* target = (long long*) pTarget;
    std::cerr << "C 0x" << std::hex << (*target) << " (" << std::dec << (*target) << ")" <<std::endl;
}