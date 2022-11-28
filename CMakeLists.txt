cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)

project(sample-grpc-cpp)

cmake_policy(SET CMP0076 NEW)

##### Set up conan

set(CONAN_DISABLE_CHECK_COMPILER True CACHE BOOL "" FORCE )
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

##### Add targets

add_executable(sample-grpc-cpp)

##### Set variables

set(LIBS_LIST
	${CONAN_LIBS}
)

set(INCLUDES_LIST
	include
	protos
	${CONAN_INCLUDE_DIRS}
)

file(GLOB_RECURSE SOURCES_SRC
	src/*.cpp
)

file(GLOB_RECURSE SOURCES_PROTOS
	protos/rpc/*.cc
)

set(SOURCES_LIST
	${SOURCES_SRC}
	${SOURCES_PROTOS}
)

##### Set include directories

target_include_directories(sample-grpc-cpp
	PUBLIC
		${INCLUDES_LIST}
)

##### Set link libraries

target_link_libraries(sample-grpc-cpp
		${LIBS_LIST}
)

##### Set sources

target_sources(sample-grpc-cpp
	PRIVATE
		${SOURCES_LIST}
)

