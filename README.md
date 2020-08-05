# DriftFX - The Direct Rendering Infrastructure for JavaFX

DriftFX allows you to render any OpenGL content directly into JavaFX nodes.  
Direct means that there is no transfer between GPU and main memory. The textures never leave the GPU.

#### Changes

 * Added the concept of a Swapchain which holds all native resources and allows better resource management.
 * Moved most of the business logic from C++ to Java
 * Added a C++ Binding to allow drift usage from C++ code

### Builds

#### Nightly Builds

This build triggers on push to master.   
It uses the version 999.0.0 with the git commit timestamp and the short git sha as qualifier.   
The artifacts are published as p2 repository and as maven snapshot. Note: nexus sets its own qualifier which is always later than the git commit timestamp.
The nightly p2 repos are at https://download.eclipse.org/efxclipse/driftfx/nightly/
The maven snapshots are at https://repo.eclipse.org/content/groups/efxclipse/

#### Release Builds

Release builds are triggered by creating a tag beginning with v followed by the version number.    
The artifacts are also published as p2 repository and as maven releases.
The links to the repos can be found in the corresponding github releases.

### Java Usage

```java
	// you acquire the Renderer api by calling getRenderer on your surface
	Renderer renderer = GLRenderer.getRenderer(surface)

	// on your render thread you do the following:
	
	// first you create your own opengl context & make it current
	
	// in your render loop you manage your swapchain instance
	
	// you can fetch the current size of the surface by asking the renderer
	Vec2i size = renderer.getSize();
	
	if (swapchain == null || size.x != swapchain.getConfig().size.x || size.y != swapchain.getConfig().size.y) {
		// re-create the swapchain
		if (swapchain != null) {
			swapchain.dispose();
		}
		swapchain = renderer.createSwapchain(new SwapchainConfig(size, 2, PresentationMode.MAILBOX, StandardTransferTypes.MainMemory);
	}
	
	
	// to draw you acquire a RenderTarget from the swapchain
	RenderTarget target = swapchain.acquire(); // this call is blocking, if there is no RenderTarget available it will wait until one gets available
	
	int texId = GLRenderer.getGLTextureId(target);
	
	// now you setup a framebuffer with this texture and draw onto it
	
	// once you are finished with the frame you call present on the swapchain
	swapchain.present(target);

```

### C++ Usage
The cpp bindings are based on a header file (`driftcpp.h`) and a source file (`driftcpp.cpp`)  you have to include in your project.
The initialization is done by calling `driftfx::initialize(JNIEnv* env, jobject classLoader)`. The jni env needs to be a valid jni env and the classLoader has to be the java class loader which has access to the `org.eclipse.fx.drift` package. On a plain java 8 this could be the system class loader, in an osgi environment it needs to be a classloader which has access to the package, and on java 11 .. (TBD jigsaw stuff).
The API aims to be similar to the Java API.

```c++
	// include the cpp bindings header
	#include "driftcpp.h"

	// first you need to initialize the cpp bindings:
	driftfx::initialize(env, classLoader); // its important that the passed in classLoader has access to the org.eclipse.fx.drift package!

	// you can also dispose the cpp bindings again by calling
	driftfx::dispose(env);

	// the entrypoint is to acquire a C++ Renderer by passing in the Java Renderer
	// this should happen on your renderer thread
	// you may need to attach your thread to the jvm to acquire a vaild JNIEnv
	
	driftfx::Renderer* renderer = driftfx::initializeRenderer(env, javaRenderer);
	
	
	
	// then you create your own opengl context & make it current
	
	// in your renderloop
	
	if (swapchain == null || needsResize()) {
	
		if (swapchain != null) {
			delete swapchain;
		}
	
		driftfx::SwapchainConfig cfg;
		cfg.imageCount = 2;
		cfg.size = renderer->getSize();
		cfg.transferType = driftfx::StandardTransferTypes::MainMemory;
		swapchain = renderer->createSwapchain(cfg);
	}
	
	
	driftfx::RenderTarget* target = swapchain->acquire();
	
	GLuint texId = driftfx::GLRenderer::getGLTextureId(target);
	
	// setup framebuffer and draw
	
	swapchain->present(target);
	
```


### TransferModes

The different ways to transfer the texture to JavaFX are now implemented as `TransferMode`s.    
       
 * **MainMemory**: *(available in Windows, Linux and MacOS)*    
   downloads the texture to main memory and uploads it again to the javafx texture.     
    
 * **IOSurface**: *(available in MacOS)*    
   shares the texture on the graphics card via the IOSurface system.    
    
    
 * **NVDXInterop**: *(available in Windows)*    
   shares the texture via the NV_DX_Interop extension with DirectX and via a direct x shared resource with javafx.


### Requirements

 * **Java 8**
 * Windows Vista or newer (only the prism Direct3D9Ex backend is supported)
 * On Windows the GPU must support **NV_DX_interop**

 
### Known issues
 * Intel HD Graphics 4000 (10.18.10.5059): **NV_DX_interop** has issues if new IDirect3D9Texture's get the same address as already disposed ones.
 * Windows 7 / nvidia: the nvidia driver deadlocks - this seems related to the NV_DX_interop calls (there is a `-Ddriftfx.winfallback=true` option which moves the pixel data on windows through main memory between opengl and directx)
 * Linux / intel: Drift does not work - it fails with i965: Failed to submit batchbuffer: No such file or directory
 
