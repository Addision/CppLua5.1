
cmake_minimum_required (VERSION 2.8)

project (CppLua)

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

aux_source_directory(. DIR_SRCS)
include_directories(/home/laij/lua-5.1.5/src )

add_executable(CppLua ${DIR_SRCS})

target_link_libraries(CppLua dl liblua.a)

