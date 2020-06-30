cmake_minimum_required(VERSION 3.1)
project(DriftCPP CXX)

message ("why?")

set(DriftCPP-Headers
	include/DriftFX/Export.h
	include/DriftFX/driftcpp.h
)

# list each source file individually
set(DriftCPP-Sources
	
	src/driftcppint.h
	src/driftcpp.cpp
)
list(APPEND DriftCPP-Sources ${DriftCPP-Headers})


# specify where our headers are
include_directories(include)

add_library(driftcpp SHARED ${DriftCPP-Headers} ${DriftCPP-Sources})
target_include_directories(driftcpp PUBLIC include)

set_property(TARGET driftcpp PROPERTY POSITION_INDEPENDENT_CODE ON)
target_compile_definitions(driftcpp PRIVATE BUILDING_DLL)

target_link_libraries(driftcpp PUBLIC driftfx)

target_include_directories(driftcpp PRIVATE ${IncludeDirectories})



