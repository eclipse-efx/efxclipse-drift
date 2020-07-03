cmake_minimum_required(VERSION 3.1)
project(samples)

include_directories(${JNI_INCLUDE_DIRS})
include_directories(${DRIFTFX_INCLUDE_DIRS})

list(APPEND SourcesList SimpleColorSample)
list(APPEND SourcesList SimpleTriangleSample)



# we need glew
# we build it ourselves here
set(Glew-Headers
	glew/include/GL/glew.h
	glew/include/GL/eglew.h
	glew/include/GL/glxew.h
	glew/include/GL/wglew.h
	)

set(Glew-Sources
	glew/src/glew.c
	)
	
		
add_library(glew OBJECT ${Glew-Headers} ${Glew-Sources})
target_include_directories(glew PUBLIC glew/include)
target_compile_definitions(glew PUBLIC GLEW_STATIC)



# context creation
set(minctx-Headers
	minctx/include/minctx.h
)

if (WIN32)
list(APPEND minctx-Sources minctx/src/minctx_win32.cpp)
endif(WIN32)

add_library(minctx OBJECT ${minctx-Headers} ${minctx-Sources})
target_link_libraries(minctx PRIVATE glew)
target_include_directories(minctx PUBLIC minctx/include)


# we're building a library
add_library(samples SHARED ${SourcesList})
target_link_libraries(samples PRIVATE glew)
target_link_libraries(samples PRIVATE minctx)
target_link_libraries(samples PRIVATE driftfx)
target_link_libraries(samples PRIVATE ${LinkLibraries})

# TODO !?!?!
#target_include_directories(samples PRIVATE ../driftcpp/include)

target_include_directories(samples PRIVATE driftcpp)
target_link_libraries(samples PRIVATE driftcpp)

target_include_directories(samples PRIVATE ${IncludeDirectories})
target_include_directories(samples PRIVATE glew)
set_property(TARGET samples PROPERTY POSITION_INDEPENDENT_CODE ON)
	
	
add_custom_command(TARGET samples POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE_DIR:driftcpp>/$<TARGET_FILE_NAME:driftcpp> "${CMAKE_SOURCE_DIR}/../org.eclipse.fx.drift.samples.cpp/native/"
	COMMENT "Copy driftcpp shared lib to java project"
	COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE_DIR:samples>/$<TARGET_FILE_NAME:samples> "${CMAKE_SOURCE_DIR}/../org.eclipse.fx.drift.samples.cpp/native/"
	COMMENT "Copy samples shared lib to java project")