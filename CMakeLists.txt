cmake_minimum_required(VERSION 2.8)

add_definitions(-std=c++11 -stdlib=libc++)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

set(SOURCE "")

project(Life++)

add_subdirectory(src)
include_directories(include)

add_executable(Life++ ${SOURCE})
target_link_libraries(Life++ c++ ncurses pthread)
