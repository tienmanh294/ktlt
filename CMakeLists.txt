cmake_minimum_required(VERSION 3.8)
#cmake --build . -j 12
set(This ktlt)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)   
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

set(Headers
    include/Issue.h
    include/Project.h
    include/main.h
    include/Task.h
    include/User.h
    include/Utils.h
    include/System.h
)
set(Sources
    src/Issue.cpp
    src/main.cpp
    src/Project.cpp
    src/Task.cpp
    src/User.cpp
    src/Utils.cpp
    src/System.cpp
)
add_library(${This} STATIC ${Sources} ${Headers})
add_subdirectory(unittest)
add_executable(main ${Sources} ${Headers})