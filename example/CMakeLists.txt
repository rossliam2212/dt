cmake_minimum_required(VERSION 3.21)
project(dt_examples)

set(CMAKE_CXX_STANDARD 17)

# Add the include directories
include_directories(/usr/local/include)

# Find the dt library
find_package(dt PATHS /usr/local/lib REQUIRED)

# Add the source files
set(SOURCE_FILES example.cpp)

# Create the executable
add_executable(dt_examples ${SOURCE_FILES})

# Link against the dt library
target_link_libraries(dt_examples PRIVATE ${DT_LIBRARIES})