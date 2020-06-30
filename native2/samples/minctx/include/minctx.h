
#ifndef _MINCTX_H_
#define _MINCTX_H_

namespace minctx {
	struct Context {

	};

	Context* CreateContext(Context* sharedContext, int majorHint, int minorHint);
	
	void DestroyContext(Context* context);

	void* GetNativeContextHandle(Context* context);

	bool MakeContextCurrent(Context* context);

	bool IsContextCurrent(Context* context);
	
}

#endif // _MINCTX_H_

















