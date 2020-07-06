cmake_minimum_required(VERSION 3.1)
project(utils CXX)

set(PUBLIC_HDR_DIR      include)


# public headers are always in include/${TARGET}/
file(GLOB_RECURSE Utils-Headers ${PUBLIC_HDR_DIR}/${TARGET}/*.h)

# list each source file individually
set(Utils-Sources
    src/JNIHelper.cpp
    src/Logger.cpp
)

# specify where our headers are
include_directories(${PUBLIC_HDR_DIR})

# add object target
add_library(lib-utils-obj OBJECT ${Utils-Headers} ${Utils-Sources})
target_include_directories(lib-utils-obj PUBLIC include)
set_property(TARGET lib-utils-obj PROPERTY POSITION_INDEPENDENT_CODE ON)
target_compile_definitions(lib-utils-obj PRIVATE BUILDING_DLL)
target_include_directories(lib-utils-obj PRIVATE ${IncludeDirectories})

