cmake_minimum_required(VERSION 3.27)
project(PingPong)

add_executable(PingPong)
target_compile_features(PingPong PRIVATE cxx_std_23)
target_sources(PingPong PRIVATE main.cpp)