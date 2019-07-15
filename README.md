# DriftFX - The Direct Rendering Infrastructure for JavaFX

DriftFX allows you to render any OpenGL content directly into JavaFX nodes.  
Direct means that there is no transfer between GPU and main memory. The textures never leave the GPU.


#### Usage

Create a `DriftFXSurface` Node in JavaFX. Instantiate a native renderer via JNI and tell it the surface id. In the native renderloop acquire a `RenderTarget` from DriftFX and setup a FBO with the supplied texture id. After rendering the content give the `RenderTarget` back to DriftFX.

Here is an example:  

##### JavaFX part

```java
public class DriftFXDemo extends Application {
	@Override
	public void start(Stage primaryStage) throws Exception {
		DriftFXSurface.initialize();
		
		BorderPane root = new BorderPane();
		Scene scene = new Scene(root);
		primaryStage.setScene(scene);
		
		DriftFXSurface surface = new DriftFXSurface();
		root.setCenter(surface);
		
		primaryStage.show();
		
		Thread renderer = new Thread(()->nRun(surface.getSurfaceId());
		renderer.start();
	}
	
	private static native void nRun(long surfaceId);
}
```

##### Native part

```c++
#include <DriftFX/DriftFX.h>
#include <DriftFX/DriftFXSurface.h>
#include <DriftFX/GL/GLContext.h>

using namespace driftfx;
using namespace driftfx::gl;

DriftFXSurface* surface;
GLContext* context;
GLuint fbo;

void prepare() {
	surface->Initialize();
	glGenFramebuffers(1, &fbo);
}
void renderFrame() {
	RenderTarget* target = surface->Acquire();
	
	glBindFramebuffer(GL_FRAMEBUFFER, fbo);
	glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, target->GetGLTexture(), 0);
	
	glViewport(0, 0, target->GetWidth(), target->GetHeight());
	glClear(GL_COLOR_BUFFER_BIT);
	
	glFlush();
	
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	
	surface->Present(target, CENTER);
}
void cleanup() {
	surface->Cleanup();
	glDeleteFramebuffers(1, &fbo);
}

extern "C" JNIEXPORT void JNICALL Java_DriftFXDemo_nRun(JNIEnv* env, jclass cls, jlong surfaceId) {
	surface = DriftFX::Get()->GetSurface(surfaceId);
	context = surface->GetContext();
	
	context->SetCurrent();	
	prepare();
	while(alive) {
		renderFrame();
	}
	cleanup();
}

```

### TransferModes

The different ways to transfer the texture to JavaFX are now implemented as `TransferMode`s. There is an API on the `DriftFXSurface` to query the available transfer modes (`DriftFXSurface.getAvailableTransferModes()`), the platform default transfer mode (`DriftFXSurface.getPlatformDefaultTransferMode()`) and the fallback transfer mode (`DriftFXSurface.getFallbackTransferMode()`). Each instance of `DriftFXSurface` has a transfer mode property. It is initialized with the default transfer mode, which is either the platform default or, if the configuration is set to fallback the fallback transfer mode.

```
DriftFXSurface.getAvailableTransferModes(); // returns a list of available transfer modes.
DriftFXSurface.getPlatformDefaultTransferMode(); // returns the platform default transfer mode.
DriftFXSurface.getFallbackTransferMode(); // returns the fallback transfer mode.

DriftFXSurface surface = new DriftFXSurface();
surface.setTransferMode(mode); // sets the transfer mode on the instance
```

At the moment the following implementations exist:    

 * **NoOp**: *(available in Windows, Linux and MacOS)*    
   As its name says it does nothing, however a valid texture is generated on acquire so your render loop will still work.    
       
       
 * **MainMemory**: *(available in Windows, Linux and MacOS)*    
   downloads the texture to main memory and uploads it again to the javafx texture.    
   *Fallback for all platforms*    
       
    
 * **IOSurface**: *(available in MacOS)*    
   shares the texture on the graphics card via the IOSurface system.    
   *MacOS Platform Default*    
    
    
 * **NVDXInterop**: *(available in Windows)*    
   shares the texture via the NV_DX_Interop extension with DirectX and via a direct x shared resource with javafx.    
   *Windows Platform Default*   
    
    
 * **SharedContext**: *(available in Linux)*    
   shares the texture via a shared gl context with javafx.    
   *Linux Platform Default*    
    
    
 * **LegacyWinFallback**: *(available in Windows)*    
   downloads the texture from gl to main memory and uploads it again to direct x, then it is shared via a dx shared resource with javafx.
   

### Requirements

 * **Java 8**
 * Windows Vista or newer (only the prism Direct3D9Ex backend is supported)
 * On Windows the GPU must support **NV_DX_interop**

 
### Known issues
 * Intel HD Graphics 4000 (10.18.10.5059): **NV_DX_interop** has issues if new IDirect3D9Texture's get the same address as already disposed ones.
 * Windows 7 / nvidia: the nvidia driver deadlocks - this seems related to the NV_DX_interop calls (there is a `-Ddriftfx.winfallback=true` option which moves the pixel data on windows through main memory between opengl and directx)
 * Linux / intel: Drift does not work - it fails with i965: Failed to submit batchbuffer: No such file or directory
 
