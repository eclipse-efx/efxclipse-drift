cmake_minimum_required(VERSION 3.1)
project(samples)

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

find_package(JNI REQUIRED)
include_directories(${JNI_INCLUDE_DIRS})

find_package(OpenGL REQUIRED)

if (WIN32)
set(DRIFTFX_LIBRARIES 
	"${CMAKE_SOURCE_DIR}/../../org.eclipse.fx.drift/native/driftfx.dll")
endif (WIN32)

if (LINUX)
set(DRIFTFX_LIBRARIES 
	"${CMAKE_SOURCE_DIR}/../../org.eclipse.fx.drift/native/libdriftfx.so")
endif (LINUX)

if (APPLE)
set(DRIFTFX_LIBRARIES 
	"${CMAKE_SOURCE_DIR}/../../org.eclipse.fx.drift/native/libdriftfx.dylib")
endif (APPLE)

set(DRIFTFX_INCLUDE_DIRS 
	${CMAKE_SOURCE_DIR}/../../org.eclipse.fx.drift/src-native/DriftFX/include
	${CMAKE_SOURCE_DIR}/../../org.eclipse.fx.drift/src-native/lib/glew/include
	${CMAKE_SOURCE_DIR}/../../org.eclipse.fx.drift/src-native/lib/utils/include
)

include_directories(${DRIFTFX_INCLUDE_DIRS})

list(APPEND SourcesList SimpleColorRenderer)
list(APPEND SourcesList SimpleTriangleRenderer)


# we're building a library
add_library(samples SHARED ${SourcesList})

target_link_libraries(samples ${DRIFTFX_LIBRARIES} ${OPENGL_LIBRARIES})

set_property(TARGET samples PROPERTY POSITION_INDEPENDENT_CODE ON)
	
	
if (WIN32)
	set_target_properties(samples
		PROPERTIES PREFIX "")
endif (WIN32)
	
		
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
		