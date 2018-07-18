cmake_minimum_required(VERSION 3.1)
project(glew)

set(PUBLIC_HDR_DIR      include)

# glew specific
add_compile_definitions(GLEW_STATIC)
#add_compile_definitions(GLEW_BUILD)

set(PUBLIC_HDRS
	include/GL/glew.h
	include/GL/eglew.h
	include/GL/glxew.h
	include/GL/wglew.h
)

set(SRCS
    src/glew.c
)

include_directories(${PUBLIC_HDR_DIR})
add_library(glew STATIC ${PUBLIC_HDRS} ${SRCS})
target_include_directories(glew PUBLIC ${PUBLIC_HDR_DIR})

if (WIN32)
	target_link_libraries(glew PRIVATE opengl32 gdi32)
endif()

set_property(TARGET glew PROPERTY POSITION_INDEPENDENT_CODE ON)



