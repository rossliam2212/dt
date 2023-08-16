cmake_minimum_required(VERSION 3.21)
project(dt_examples)

set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/local/include)

find_package(dt REQUIRED)

set(SOURCE_FILES example.cpp)

add_executable(dt_examples ${SOURCE_FILES})

target_link_libraries(dt_examples PRIVATE ${DT_LIBRARIES})