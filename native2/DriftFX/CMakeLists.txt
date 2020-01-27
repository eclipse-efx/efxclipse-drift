cmake_minimum_required(VERSION 3.1)
project(DriftFX CXX)

# configuring msvc to include the runtime
#if (WIN32)
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MT")
#endif (WIN32)

set(DriftFX-Headers
	include/DriftFX/Common.h
	include/DriftFX/DriftFX.h
	include/DriftFX/DriftFXSurface.h
	include/DriftFX/RenderTarget.h
	include/DriftFX/Context.h
	include/DriftFX/Texture.h
	include/DriftFX/GL/GLContext.h
	include/DriftFX/GL/GLTexture.h
	include/DriftFX/math/Vec2.h
	
)

# list each source file individually
set(DriftFX-Sources

	src/ng/GL.cpp
	src/ng/SYS.cpp
	
	src/ng/gl_context.h
	#src/ng/gl_context_glx.cpp
	src/ng/gl_context_wgl.cpp
	src/ng/gl_context_jni.cpp
	src/ng/gl_context_procs.h
	src/ng/gl_context_procs.cpp

	src/SurfaceData.h
	
    src/Context.cpp
    
    src/JNINativeSurface.h
    src/JNINativeSurface.cpp
    
    src/NativeSurface.h
    src/NativeSurface.cpp
    
    src/NativeSurfaceAPI.cpp
    
    src/NativeSurfaceRegistry.h
    src/NativeSurfaceRegistry.cpp
    
    src/RenderTarget.cpp
    
    src/SharedTexture.h
    src/SharedTexture.cpp
    
    src/Texture.cpp
    
    src/gl/GL.cpp
    src/gl/GLContext.cpp
    src/gl/GLTexture.cpp
    
    src/prism/PrismBridge.cpp
    
    src/DriftFXSurface.cpp
    src/InternalDriftFX.cpp
    
    src/gl/InternalGLContext.h
    src/gl/InternalGLContext.cpp
    
    src/Configuration.h
    src/Configuration.cpp
    
    src/math/Vec2.cpp
    
    src/gl/GLLog.h
    src/gl/GLLog.cpp
    
    
    src/MainMemorySharedTexture.h
    src/MainMemorySharedTexture.cpp
    
    src/NoopSharedTexture.h
    src/NoopSharedTexture.cpp
    
    src/FrameManager.h
    src/FrameManager.cpp
    
    src/TransferModeManager.h
	src/TransferModeManager.cpp
	
	src/NoOpTransferMode.cpp
	
	src/SharedTexturePool.h
	src/SharedTexturePool.cpp
	
	src/GPUSyncUtil.cpp
	
	src/jni/jniutil.h
	src/jni/jniutil.cpp
	src/jni/JNITiming.h
	src/jni/JNITiming.cpp
	
	src/FrameNativeAPI.cpp
	
	src/jni/JNISwapChain.h
	src/jni/JNISwapChain.cpp
	
	src/SharedTextureSwapChain.h
	src/SharedTextureSwapChain.cpp
)
list(APPEND DriftFX-Sources ${DriftFX-Headers})

if (WIN32)

	list(APPEND DriftFX-Sources src/ng/D3DBatch.cpp)

	list(APPEND DriftFX-Sources src/gl/wgl/WGLGLContext.h)
	list(APPEND DriftFX-Sources src/gl/wgl/WGLGLContext.cpp)
	
	list(APPEND DriftFX-Sources src/prism/d3d/D3DPrismBridge.h)
	list(APPEND DriftFX-Sources src/prism/d3d/D3dPrismBridge.cpp)

	list(APPEND DriftFX-Sources src/prism/d3d/D3DNativeSurface.h)
	list(APPEND DriftFX-Sources src/prism/d3d/D3DNativeSurface.cpp)
	
	list(APPEND DriftFX-Sources src/prism/d3d/D3DSharedTexture.h)
	list(APPEND DriftFX-Sources src/prism/d3d/D3DSharedTexture.cpp)
	
	list(APPEND DriftFX-Sources src/prism/d3d/D3DSharedFallbackTexture.h)
	list(APPEND DriftFX-Sources src/prism/d3d/D3DSharedFallbackTexture.cpp)
	
	list(APPEND DriftFX-Sources src/prism/d3d/NativeAPI)
	
	list(APPEND DriftFX-Sources src/win32/D3D9ExContext.h)
	list(APPEND DriftFX-Sources src/win32/D3D9ExContext.cpp)

	list(APPEND DriftFX-Sources src/win32/D3D9Texture.h)
	list(APPEND DriftFX-Sources src/win32/D3D9Texture.cpp)

	list(APPEND DriftFX-Sources src/win32/Error.h)
	list(APPEND DriftFX-Sources src/win32/Error.cpp)
	
	list(APPEND DriftFX-Sources src/prism/d3d/MainMemoryTransferMode.cpp)
	list(APPEND DriftFX-Sources src/prism/d3d/NVDXInteropTransferMode.cpp)
	list(APPEND DriftFX-Sources src/prism/d3d/LegacyWinFallbackTransferMode.cpp)

endif (WIN32)

if (LINUX)
	list(APPEND DriftFX-Sources src/gl/glx/GLXGLContext)
	
	list(APPEND DriftFX-Sources src/prism/es2/ES2PrismBridge)
	list(APPEND DriftFX-Sources src/prism/es2/ES2NativeSurface)
	list(APPEND DriftFX-Sources src/prism/es2/NativeAPI)
	
	list(APPEND DriftFX-Sources src/prism/es2/glx/GLXES2PrismBridge)
	list(APPEND DriftFX-Sources src/prism/es2/glx/GLXSharedTexture)
	list(APPEND DriftFX-Sources src/prism/es2/glx/NativeAPI)

	list(APPEND DriftFX-Sources src/prism/es2/MainMemoryTransferMode.cpp)
	list(APPEND DriftFX-Sources src/prism/es2/glx/SharedContextTransferMode.cpp)
endif (LINUX)


if (APPLE)
	list(APPEND DriftFX-Sources src/gl/cgl/cgl)
	list(APPEND DriftFX-Sources src/gl/cgl/CGLGLContext)
	list(APPEND DriftFX-Sources src/gl/cgl/cgl_context)
	
	list(APPEND DriftFX-Sources src/prism/es2/ES2PrismBridge)
	list(APPEND DriftFX-Sources src/prism/es2/ES2NativeSurface)
	list(APPEND DriftFX-Sources src/prism/es2/NativeAPI)
	
	list(APPEND DriftFX-Sources src/prism/es2/cgl/CGLES2PrismBridge)
	list(APPEND DriftFX-Sources src/prism/es2/cgl/IOSurfaceSharedTexture)
	list(APPEND DriftFX-Sources src/prism/es2/cgl/NativeAPI)
	
	list(APPEND DriftFX-Sources src/gl/cgl/CGLLog.h)
	list(APPEND DriftFX-Sources src/gl/cgl/CGLLog.cpp)
	

	list(APPEND DriftFX-Sources src/prism/es2/MainMemoryTransferMode.cpp)
	list(APPEND DriftFX-Sources src/prism/es2/cgl/IOSurfaceTransferMode.cpp)
endif (APPLE)


# specify where our headers are
include_directories(include)
include_directories(src)

add_library(driftfx SHARED ${DriftFX-Headers} ${DriftFX-Sources} $<TARGET_OBJECTS:lib-glew-obj> $<TARGET_OBJECTS:lib-utils-obj>)
target_include_directories(driftfx PUBLIC include)
set_property(TARGET driftfx PROPERTY POSITION_INDEPENDENT_CODE ON)
target_compile_definitions(driftfx PRIVATE BUILDING_DLL)

target_link_libraries(driftfx PUBLIC lib-utils-obj)
target_link_libraries(driftfx PUBLIC lib-glew-obj)
target_link_libraries(driftfx PRIVATE ${LinkLibraries})
if (LINUX)
	target_link_libraries(driftfx PRIVATE "atomic")
endif (LINUX)
target_include_directories(driftfx PRIVATE ${IncludeDirectories})


