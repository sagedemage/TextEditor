cmake_minimum_required(VERSION 3.22)

project(cli_app)

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")

# set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

add_executable(main src/main.cpp src/message/message.cpp)