cmake_minimum_required(VERSION 3.1)
project(glew)


set(Glew-Headers
	include/GL/glew.h
	include/GL/eglew.h
	include/GL/glxew.h
	include/GL/wglew.h
	)

set(Glew-Sources
	src/glew.c
	)

add_library(lib-glew-obj OBJECT ${Glew-Headers} ${Glew-Sources})
target_include_directories(lib-glew-obj PUBLIC "include")
target_compile_definitions(lib-glew-obj PUBLIC GLEW_STATIC)
set_property(TARGET lib-glew-obj PROPERTY POSITION_INDEPENDENT_CODE ON)
target_include_directories(lib-glew-obj PRIVATE ${IncludeDirectories})

if (WIN32)
	target_link_libraries(lib-glew-obj PUBLIC opengl32 gdi32)
endif(WIN32)




