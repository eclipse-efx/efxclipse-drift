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

### Requirements

 * **Java 8**
 * Windows Vista or newer (only the prism Direct3D9Ex backend is supported)
 * On Windows the GPU must support **NV_DX_interop**

 
### Known issues
 * Intel HD Graphics 4000 (10.18.10.5059): **NV_DX_interop** has issues if new IDirect3D9Texture's get the same address as already disposed ones.
 * Windows 7 / nvidia: the nvidia driver deadlocks - this seems related to the NV_DX_interop calls (there is a `-Ddriftfx.winfallback=true` option which moves the pixel data on windows through main memory between opengl and directx)
 * Linux / intel: Drift does not work - it fails with i965: Failed to submit batchbuffer: No such file or directory
 
