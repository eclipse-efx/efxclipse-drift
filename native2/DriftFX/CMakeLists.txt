cmake_minimum_required(VERSION 3.1)
project(DriftFX CXX)

# configuring msvc to include the runtime
#if (WIN32)
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MT")
#endif (WIN32)

if (LINUX)
	add_definitions(-DDRIFTGL_GLX)
endif (LINUX)

if (WIN32)
	add_definitions(-DDRIFTGL_WGL)
endif(WIN32)

if (APPLE)
	add_definitions(-DDRIFTGL_CGL)
endif (APPLE)

set(DriftFX-Headers
)

# list each source file individually
set(DriftFX-Sources

	src/MemoryStack.cpp

	src/jni_GL.cpp
	src/jni_SYS.cpp

	src/JNIHelper.cpp
	
)
list(APPEND DriftFX-Sources ${DriftFX-Headers})

if (WIN32)

list(APPEND DriftFX-Sources src/jni/win32/Prism.cpp)
list(APPEND DriftFX-Sources src/jni/win32/NV_DX_Interop.cpp)
list(APPEND DriftFX-Sources src/jni/win32/WindowsError.cpp)

list(APPEND DriftFX-Sources src/jni/win32/Win32.cpp)
list(APPEND DriftFX-Sources src/jni/win32/D3D9.cpp)
list(APPEND DriftFX-Sources src/jni_D3DBatch.cpp)	


endif (WIN32)

if (LINUX)

endif (LINUX)


if (APPLE)

list(APPEND DriftFX-Sources src/jni/macos/MacOS.cpp)
list(APPEND DriftFX-Sources src/jni/macos/cgl_context.m)

endif (APPLE)


# specify where our headers are
include_directories(include)
include_directories(src)

add_library(driftfx SHARED ${DriftFX-Headers} ${DriftFX-Sources})

target_include_directories(driftfx PUBLIC include)
set_property(TARGET driftfx PROPERTY POSITION_INDEPENDENT_CODE ON)
#target_compile_definitions(driftfx PRIVATE BUILDING_DLL)

target_link_libraries(driftfx PUBLIC DriftGL)
target_link_libraries(driftfx PRIVATE ${LinkLibraries})
if (LINUX)
	target_link_libraries(driftfx PRIVATE "atomic")
endif (LINUX)
target_include_directories(driftfx PRIVATE ${IncludeDirectories})


