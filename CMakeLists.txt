cmake_minimum_required(VERSION 3.5)
project(PingPong)



set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

add_executable(PingPong ${SOURCE_DIR}/main.cpp)
if(CMAKE_VERSION VERSION_GREATER_EQUAL "3.8")
    target_compile_features(PingPong PRIVATE cxx_std_23)
else()
    set(CMAKE_CXX_STANDARD 23)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()
