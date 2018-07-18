cmake_minimum_required(VERSION 3.11)

project(releng)

if (UNIX AND NOT APPLE)
	set(LINUX TRUE)
endif ()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


if (WIN32)
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-rpath,$$ORIGIN -Wl,--export-all-symbols -static-libgcc -static-libstdc++ -static -lpthread")
endif (WIN32)

if (APPLE)
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-rpath,$$ORIGIN  -static-libgcc -static-libstdc++ -static -lpthread")
endif (APPLE)

enable_testing()

if (APPLE)
  # since apple deprecated OpenGL we do not want to see this during the build
  add_compile_definitions(GL_SILENCE_DEPRECATION)
endif (APPLE)

add_compile_definitions(GLEW_STATIC)

# JNI
# TODO improve this (look for jdk8 JNI)
find_package(JNI REQUIRED)

message("JNI: " ${JNI_INCLUDE_DIRS})
message("JNI: " ${JNI_LIBRARIES})

# OpenGL
find_package(OpenGL REQUIRED)

if (WIN32)
	# DirectX
	# TODO improve this
	set(DIRECTX_INCLUDE_DIRS 
		"C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Include")
	set(DIRECTX9_LIBRARIES 
		"C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Lib/x64/d3d9.lib"
		"C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Lib/x64/d3dx9.lib"
		)
endif (WIN32)


include_directories(${JNI_INCLUDE_DIRS})

if (APPLE)
# Add macos framework symlinks for CDT
include_directories( "../../MacOSFrameworks/" )
include_directories( "../../JNIHeader/" )
endif (APPLE)

add_subdirectory(lib/glew)
add_subdirectory(lib/utils)

add_subdirectory(DriftFX)


list(APPEND LinkLibraries ${OPENGL_LIBRARIES})

if (WIN32)
list(APPEND LinkLibraries ${DIRECTX9_LIBRARIES})
endif (WIN32)


if (APPLE)
list(APPEND LinkLibraries "-framework OpenGL")
list(APPEND LinkLibraries "-framework Cocoa")
list(APPEND LinkLibraries "-framework IOSurface")
list(APPEND LinkLibraries "-framework CoreFoundation")
endif (APPLE)

add_library(driftfx SHARED DriftFX/src/null.cpp)

if (WIN32)
set(LIB_NAME driftfx.dll)

	set_target_properties(driftfx
		PROPERTIES PREFIX "")

	target_link_libraries(driftfx
			"-Wl,--whole-archive"
			glew
			utils
			DriftFX
			"-Wl,--no-whole-archive"
			${LinkLibraries}
		)

endif (WIN32)

if (APPLE)
set(LIB_NAME libdriftfx.dylib)
target_link_options(driftfx PRIVATE "-Wl,-all_load")
target_link_libraries(driftfx
			${LinkLibraries}
			"-Wl,-all_load"
			DriftFX
			utils
			glew
		)
endif (APPLE)

if (LINUX)
	set(LIB_NAME libdriftfx.so)
	
	target_link_libraries(driftfx
		${LinkLibraries}
		"-Wl,--whole-archive"
		DriftFX
		utils
		glew
		"-Wl,--no-whole-archive"
	)

endif (LINUX)



add_custom_command(TARGET driftfx POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different
		"$<TARGET_FILE:driftfx>"
		"${PROJECT_SOURCE_DIR}/../native/${LIB_NAME}")
		
		
add_custom_target(debug
	COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Debug ${CMAKE_SOURCE_DIR}
	COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all
	COMMENT "Creating binaries in debug mode"
)

add_custom_target(release
	COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Release ${CMAKE_SOURCE_DIR}
	COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all
	COMMENT "Creating binaries in release mode"
)
		
