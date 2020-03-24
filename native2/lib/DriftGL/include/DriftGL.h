#ifndef DRIFTGL_H_
#define DRIFTGL_H_

#include "DriftGL_gen.h"

namespace driftgl {

	struct Context {
	};

	bool Initialize();
	bool Destroy();

	Context* CreateContext(Context* sharedContext, int majorHint, int minorHint);
	Context* CreateSharedCompatContext(Context* sharedContext);

	Context* WrapContext(long nativeContextHandle);

	void DestroyContext(Context* context);
	bool MakeContextCurrent(Context* context);
	bool IsContextCurrent(Context* context);

	void* GetNativeContextHandle(Context* context);
}


#endif
