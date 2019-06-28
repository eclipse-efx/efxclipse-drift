/*
 * Copyright (c) 2019 BestSolution.at and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     Christoph Caks <ccaks@bestsolution.at> - initial API and implementation
 */

#ifndef DRIFTFX_INTERNAL_FRAMEMANAGER_H_
#define DRIFTFX_INTERNAL_FRAMEMANAGER_H_

#include <map>
#include <mutex>

#include <DriftFX/DriftFXSurface.h>
#include <DriftFX/math/Vec2.h>

#include <SurfaceData.h>


namespace driftfx {
namespace internal {

class SharedTexture;

class Frame : public RenderTarget {
public:
	Frame(long surfaceId, long long frameId, SurfaceData surfaceData, math::Vec2ui size);
	virtual ~Frame();

	virtual void SetSharedTexture(SharedTexture* texture);
	virtual void SetPresentationHint(PresentationHint hint);

	virtual SharedTexture* GetSharedTexture();

	// from RenderTarget
	virtual unsigned int GetGLTexture();
	virtual unsigned int GetWidth();
	virtual unsigned int GetHeight();


	virtual long GetSurfaceId();
	virtual long long GetFrameId();
	virtual SurfaceData GetSurfaceData();
	virtual math::Vec2ui GetSize();
	virtual PresentationHint GetPresentationHint();

private:
	long surfaceId;
	long long frameId;
	SurfaceData surfaceData;
	math::Vec2ui size;
	PresentationHint presentationHint;
	SharedTexture* sharedTexture;
};

class FrameManager {

public:
	FrameManager(long surfaceId);
	virtual ~FrameManager();


	Frame* CreateFrame(SurfaceData surfaceData, math::Vec2ui size);

	Frame* GetFrame(long long frameId);

	void DisposeFrame(long long frameId);



private:
	long surfaceId;
	long long nextFrameId;

	std::mutex framesMutex;
	std::map<long long, Frame*> frames;

};


}
}

#endif /* DRIFTFX_SRC_FRAMEMANAGER_H_ */
