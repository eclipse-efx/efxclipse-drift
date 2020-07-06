cmake_minimum_required(VERSION 3.1)
project(samples)

include_directories(${JNI_INCLUDE_DIRS})
include_directories(${DRIFTFX_INCLUDE_DIRS})

list(APPEND SourcesList SimpleColorRenderer)
list(APPEND SourcesList SimpleTriangleRenderer)
list(APPEND SourcesList SwapChainColorRenderer)
list(APPEND SourcesList SimpleColor)

# we're building a library
add_library(samples SHARED ${SourcesList} $<TARGET_OBJECTS:lib-glew-obj> $<TARGET_OBJECTS:lib-utils-obj>)
target_link_libraries(samples PRIVATE driftfx)
target_link_libraries(samples PRIVATE ${LinkLibraries})
target_include_directories(samples PRIVATE ${IncludeDirectories})
set_property(TARGET samples PROPERTY POSITION_INDEPENDENT_CODE ON)
	
	
