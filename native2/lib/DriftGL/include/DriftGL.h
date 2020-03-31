#ifndef DRIFTGL_H_
#define DRIFTGL_H_

#include "Export.h"
#include "DriftGL_gen.h"

namespace driftgl {

	struct Context {
	};

	DRIFTGL_EXPORT bool Initialize();
	DRIFTGL_EXPORT bool Destroy();

	DRIFTGL_EXPORT Context* CreateContext(Context* sharedContext, int majorHint, int minorHint);
	DRIFTGL_EXPORT Context* CreateSharedCompatContext(Context* sharedContext);

	DRIFTGL_EXPORT Context* WrapContext(long long nativeContextHandle);

	DRIFTGL_EXPORT void DestroyContext(Context* context);
	DRIFTGL_EXPORT bool MakeContextCurrent(Context* context);
	DRIFTGL_EXPORT bool IsContextCurrent(Context* context);

	DRIFTGL_EXPORT void* GetNativeContextHandle(Context* context);
}


#endif
