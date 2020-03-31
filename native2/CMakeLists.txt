cmake_minimum_required(VERSION 3.12)

project(releng)

set( CMAKE_VERBOSE_MAKEFILE on )

if (UNIX AND NOT APPLE)
	set(LINUX TRUE)
endif ()

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	set(MSVC TRUE)
endif ()

set(CMAKE_CXX_STANDARD 11)

# configure debug symbols
if (LINUX)
 set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb")
#  set(CMAKE_CXX_CREATE_SHARED_LIBRARY
#  	"${CMAKE_CXX_CREATE_SHARED_LIBRARY}"
#  	"${CMAKE_OBJCOPY} --only-keep-debug <TARGET> <TARGET>.debug"
#  	"${CMAKE_OBJCOPY} --add-gnu-debuglink=<TARGET>.debug <TARGET>"
#  	"${CMAKE_STRIP} --strip-unneeded <TARGET>"
#  )
endif (LINUX)
if (APPLE)
  set(CMAKE_CXX_CREATE_SHARED_LIBRARY
  	"${CMAKE_CXX_CREATE_SHARED_LIBRARY}"
  	"dsymutil <TARGET>"
  	"${CMAKE_STRIP} -S <TARGET>"
  )
endif (APPLE)

if (MSVC)
	# in windows we want to always include the msvc runtime in the dll
	set (CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
	set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MT")
	set (CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL} /MT")
	set (CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} /MT")

	set (CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /NODEFAULTLIB:libc.lib /NODEFAULTLIB:libcmtd.lib /NODEFAULTLIB:msvcrt.lib /NODEFAULTLIB:libcd.lib /NODEFAULTLIB:msvcrtd.lib")
	# /VERBOSE:LIB
endif (MSVC)





# JNI
find_package(JNI REQUIRED)
# OpenGL
find_package(OpenGL REQUIRED)
if (APPLE)
  # since apple deprecated OpenGL we do not want to see this during the build
  add_compile_definitions(GL_SILENCE_DEPRECATION)
endif (APPLE)

if (WIN32)
	list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

	find_package(WindowsSDK REQUIRED)
	get_windowssdk_include_dirs(${WINDOWSSDK_LATEST_DIR} WINSDK_INCLUDE_DIRS)
	get_windowssdk_library_dirs(${WINDOWSSDK_LATEST_DIR} WINSDK_LIBRARY_DIRS)

	message("WinSDK include: ${WINSDK_INCLUDE_DIRS}")
	message("WinSDK lib: ${WINSDK_LIBRARY_DIRS}")
	find_path(DIRECTX_INCLUDE_DIRS
		NAMES d3d9.h
		HINTS ${WINSDK_INCLUDE_DIRS})

	message ("DirectX Include: ${DIRECTX_INCLUDE_DIRS}")

	find_library(DIRECTX9_LIBRARIES
		NAMES d3d9
		PATHS ${WINSDK_LIBRARY_DIRS})

	message ("DirectX9 Lib: ${DIRECTX9_LIBRARIES}")
endif (WIN32)



if (APPLE)
	# Add macos framework symlinks for CDT
	include_directories( "../../MacOSFrameworks/" )
	include_directories( "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library/Frameworks/JavaVM.framework/Versions/A/Headers/" )
	message ( "${JNI_INCLUDE_DIRS}" )
endif (APPLE)


# setup IncludeDirectories
list(APPEND IncludeDirectories ${JNI_INCLUDE_DIRS})
if (WIN32)
	list(APPEND IncludeDirectories ${DIRECTX_INCLUDE_DIRS})
endif (WIN32)


# setup LinkLibraries
if (APPLE)
	list(APPEND LinkLibraries "-framework OpenGL")
	list(APPEND LinkLibraries "-framework Cocoa")
	list(APPEND LinkLibraries "-framework IOSurface")
	list(APPEND LinkLibraries "-framework CoreFoundation")
else (APPLE)

	list(APPEND LinkLibraries ${OPENGL_LIBRARIES})

	if (WIN32)
		list(APPEND LinkLibraries ${DIRECTX9_LIBRARIES})
	endif (WIN32)

endif (APPLE)
if (LINUX)
	list(APPEND LinkLibraries X11)
endif (LINUX)

add_subdirectory(lib/DriftGL)

add_subdirectory(DriftFX)

#add_subdirectory(lib/glew)
#add_subdirectory(lib/utils)

#add_subdirectory(samples)


ENABLE_TESTING()

add_custom_target(copy
  # todo: check if debug and release folder exist
  # debug version
  COMMAND ${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/libEGLd.dll          ${CMAKE_BINARY_DIR}/Debug
)

