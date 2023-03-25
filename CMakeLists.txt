cmake_minimum_required(VERSION 3.22 VERSION 0.1.0)

project(cli_app)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O3")

add_executable(main 
    src/main.cpp 
    src/message/message.cpp
)