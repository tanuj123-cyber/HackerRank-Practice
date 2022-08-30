cmake_minimum_required(VERSION 3.9)
project(hacker_rank)

set(FLAGS "-g -O0 -fno-omit-frame-pointer -fstack-protector-strong")

set(CMAKE_CXX_FLAGS ${FLAGS})
set(CMAKE_C_FLAGS ${FLAGS})

# Output Directory Variables
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)


include_directories("${CMAKE_SOURCE_DIR}/include")


file(GLOB EQUAL_SRC src/c/Equal/main.c)


add_executable(Equal ${EQUAL_SRC})
