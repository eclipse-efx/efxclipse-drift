cmake_minimum_required(VERSION 3.1)
project(DriftGL CXX)

if (LINUX)
	add_definitions(-DDRIFTGL_GLX)
endif (LINUX)

if (WIN32)
	add_definitions(-DDRIFTGL_WGL)
endif(WIN32)

if (APPLE)
	add_definitions(-DDRIFTGL_CGL)
endif (APPLE)


#CONFIGURE_FILE( test/Test.h.in test/Test.h )

set(DriftGL-Headers
	include/DriftGL.h
	include/DriftGL_gen.h
	include/DriftGL_wgl.h
	include/DriftGL_glx.h
	include/DriftGL_cgl.h
)

set(DriftGL-Sources
	src/DriftGL.cpp
	src/DriftGL_gen.cpp
	src/DriftGL_wgl.cpp
	src/DriftGL_glx.cpp
	src/DriftGL_cgl.cpp
)


#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS 1)

add_library(DriftGL SHARED ${DriftGL-Headers} ${DriftGL-Sources})
target_include_directories(DriftGL PUBLIC include)
target_compile_definitions(DriftGL PRIVATE BUILDING_DLL)
target_link_libraries(DriftGL PRIVATE ${LinkLibraries})

install(TARGETS DriftGL DESTINATION ${CMAKE_BINARY_DIR}/../org.eclipse.fx.drift.native.win32.x86-64/native)


add_executable(test_create_context test/create_context.cpp)
target_link_libraries(test_create_context PRIVATE DriftGL)

add_executable(test_initialize test/initialize.cpp)
target_link_libraries(test_initialize PRIVATE DriftGL)


ENABLE_TESTING()
ADD_TEST(initialize test_initialize)
ADD_TEST(create_context test_create_context)

add_custom_command(TARGET DriftGL POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE_DIR:DriftGL>/$<TARGET_FILE_NAME:DriftGL> "${CMAKE_SOURCE_DIR}/../org.eclipse.fx.drift/src/main/resources/native"
	COMMENT "Copy DriftGL shared lib to java project")