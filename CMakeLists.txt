cmake_minimum_required(VERSION 3.10)
project(PingPong)



set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
add_executable(PingPong)
target_compile_features(PingPong PRIVATE cxx_std_23)
target_sources(PingPong PRIVATE ${SOURCE_DIR}/main.cpp)