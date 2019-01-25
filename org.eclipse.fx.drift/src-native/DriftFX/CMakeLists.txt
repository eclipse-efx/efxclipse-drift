cmake_minimum_required(VERSION 3.1)
project(DriftFX CXX)

set(TARGET              DriftFX)
set(PUBLIC_HDR_DIR      include)

add_compile_definitions(GLEW_STATIC)

# public headers are always in include/${TARGET}/
file(GLOB_RECURSE PUBLIC_HDRS ${PUBLIC_HDR_DIR}/${TARGET}/*.h)

set(PUBLIC_HDRS
	include/DriftFX/DriftFX.h
	include/DriftFX/DriftFXSurface.h
	include/DriftFX/RenderTarget.h
	include/DriftFX/Context.h
	include/DriftFX/Texture.h
	include/DriftFX/GL/GLContext.h
	include/DriftFX/GL/GLTexture.h
)

# list each source file individually
set(SRCS
    src/Context.cpp
    src/JNINativeSurface.cpp
    src/NativeSurface.cpp
    src/NativeSurfaceAPI.cpp
    src/NativeSurfaceRegistry.cpp
    src/RenderTarget.cpp
    src/SharedTexture.cpp
    src/Texture.cpp
    
    src/gl/GL.cpp
    src/gl/GLContext.cpp
    src/gl/GLTexture.cpp
    
    src/prism/PrismBridge.cpp
    
    src/DriftFXSurface.cpp
    src/InternalDriftFX.cpp
    
    src/gl/InternalGLContext
)

if (WIN32)
	list(APPEND SRCS src/gl/wgl/WGLGLContext)
	
	list(APPEND SRCS src/prism/d3d/D3DPrismBridge)
	list(APPEND SRCS src/prism/d3d/D3DNativeSurface)
	list(APPEND SRCS src/prism/d3d/D3DSharedTexture)
	list(APPEND SRCS src/prism/d3d/NativeAPI)
	
	list(APPEND SRCS src/win32/D3D9ExContext)
	list(APPEND SRCS src/win32/D3D9Texture)
	list(APPEND SRCS src/win32/Error)
endif (WIN32)

if (LINUX)
	list(APPEND SRCS src/gl/glx/GLXGLContext)
	
	list(APPEND SRCS src/prism/es2/ES2PrismBridge)
	list(APPEND SRCS src/prism/es2/ES2NativeSurface)
	list(APPEND SRCS src/prism/es2/NativeAPI)
	
	list(APPEND SRCS src/prism/es2/glx/GLXES2PrismBridge)
	list(APPEND SRCS src/prism/es2/glx/GLXSharedTexture)
	list(APPEND SRCS src/prism/es2/glx/NativeAPI)
endif (LINUX)


if (APPLE)
	list(APPEND SRCS src/gl/cgl/cgl)
	list(APPEND SRCS src/gl/cgl/CGLGLContext)
	list(APPEND SRCS src/gl/cgl/cgl_context)
	
	list(APPEND SRCS src/prism/es2/ES2PrismBridge)
	list(APPEND SRCS src/prism/es2/ES2NativeSurface)
	list(APPEND SRCS src/prism/es2/NativeAPI)
	
	list(APPEND SRCS src/prism/es2/cgl/CGLES2PrismBridge)
	list(APPEND SRCS src/prism/es2/cgl/IOSurfaceSharedTexture)
	list(APPEND SRCS src/prism/es2/cgl/NativeAPI)
endif (APPLE)


if (LINUX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
endif()

# specify where our headers are
include_directories(${PUBLIC_HDR_DIR})
include_directories(src)

# we're building a library
add_library(${TARGET} STATIC ${PUBLIC_HDRS} ${SRCS})

# specify where the public headers of this library are
target_include_directories(${TARGET} PUBLIC ${PUBLIC_HDR_DIR})

target_link_libraries(${TARGET} 
	PRIVATE glew
	PRIVATE utils
)

set_property(TARGET ${TARGET} PROPERTY POSITION_INDEPENDENT_CODE ON)


if (WIN32)
    target_link_libraries(${TARGET} PRIVATE opengl32 gdi32)
endif()

		
#if (APPLE)
#add_executable(phun src/Phun)
#target_link_libraries(phun DriftFX driftglew utils samples )
#target_link_libraries(phun "-framework OpenGL -framework IOSurface -framework CoreFoundation -framework Cocoa")
#target_link_options(phun PRIVATE -Wl,-all_load)
#endif (APPLE)
