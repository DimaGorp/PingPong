cmake_minimum_required(VERSION 3.5)
project(PingPong)



set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

add_executable(PingPong ${SOURCE_DIR}/main.cpp)
target_compile_features(PingPong PRIVATE cxx_std_23)