cmake_minimum_required(VERSION 3.1)
project(DriftFX CXX)

# configuring msvc to include the runtime
#if (WIN32)
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MT")
#endif (WIN32)

set(DriftFX-Headers
)

# list each source file individually
set(DriftFX-Sources

	src/2/jni_GL.cpp
	src/2/jni_SYS.cpp
	
)
list(APPEND DriftFX-Sources ${DriftFX-Headers})

if (WIN32)

	

endif (WIN32)

if (LINUX)

endif (LINUX)


if (APPLE)

endif (APPLE)


# specify where our headers are
include_directories(include)
include_directories(src)

add_library(driftfx SHARED ${DriftFX-Headers} ${DriftFX-Sources})

target_include_directories(driftfx PUBLIC include)
set_property(TARGET driftfx PROPERTY POSITION_INDEPENDENT_CODE ON)
target_compile_definitions(driftfx PRIVATE BUILDING_DLL)

target_link_libraries(driftfx PUBLIC DriftGL)
target_link_libraries(driftfx PRIVATE ${LinkLibraries})
if (LINUX)
	target_link_libraries(driftfx PRIVATE "atomic")
endif (LINUX)
target_include_directories(driftfx PRIVATE ${IncludeDirectories})


