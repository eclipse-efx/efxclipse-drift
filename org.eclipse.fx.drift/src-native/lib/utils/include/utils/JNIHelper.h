#ifndef JNIHELPER_H_
#define JNIHELPER_H_

#include <jni.h>

class JNIHelper {

public:
	static void Initialize(JavaVM* jvm);

	static bool IsThreadAttached();
	static void AttachThread();
	static void ReleaseThread();

	static JNIEnv* GetJNIEnv(bool autoAttach);

private:
	static JavaVM* jvm;
	static thread_local JNIEnv* jniEnv;

};


#endif /* JNIHELPER_H_ */
