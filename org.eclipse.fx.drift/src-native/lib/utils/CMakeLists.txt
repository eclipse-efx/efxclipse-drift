cmake_minimum_required(VERSION 3.1)
project(utils CXX)

set(TARGET              utils)
set(PUBLIC_HDR_DIR      include)

if (LINUX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
endif()

# public headers are always in include/${TARGET}/
file(GLOB_RECURSE PUBLIC_HDRS ${PUBLIC_HDR_DIR}/${TARGET}/*.h)

# list each source file individually
set(SRCS
    src/JNIHelper.cpp
    src/Logger.cpp
)

# specify where our headers are
include_directories(${PUBLIC_HDR_DIR})

# we're building a library
add_library(${TARGET} STATIC ${PUBLIC_HDRS} ${SRCS})

# specify where the public headers of this library are
target_include_directories(${TARGET} PUBLIC ${PUBLIC_HDR_DIR})

if (WIN32)
    target_link_libraries(${TARGET} PRIVATE opengl32 gdi32)
endif()

install(TARGETS ${TARGET} ARCHIVE DESTINATION lib/${DIST_DIR})


