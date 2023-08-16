### dt - C++ Date and Time Library

#### How to build & use:
#### 1. Clone repo and install.
```bash
$ git clone https://github.com/rossliam2212/dt.git
$ mikdir build && cd build
$ sudo cmake --build . --target install
```
#### 2. Setup your CMakeLists.txt.
```cmake
cmake_minimum_required(VERSION 3.21)
project(<your_project>)

set(CMAKE_CXX_STANDARD 17)

# Add the include directories
include_directories(/usr/local/include)

# Find the dt library
find_package(dt REQUIRED)

# Add the source files
set(SOURCE_FILES 
        test.cpp)

# Create the executable
add_executable(<your_project> ${SOURCE_FILES})

# Link against the dt library
target_link_libraries(<your_project> PRIVATE ${DT_LIBRARIES})
```

#### 3. Use dt.
```c++
#include <dt/date/Date.hpp>

int main() {
    dt::Date date{22, 12, 2001};
    std::cout << date << "\n";
    
    return 0;
}
```
##### Output:
```bash
22-12-2001
```
