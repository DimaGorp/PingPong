cmake_minimum_required(VERSION 3.5)
project(PingPong)



set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

add_executable(PingPong ${SOURCE_DIR}/main.cpp)
if(CMAKE_VERSION VERSION_LESS "3.20")
    set(CMAKE_CXX_STANDARD 23)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
else()
    target_compile_features(PingPong PRIVATE cxx_std_23)
endif()
find_package(SFML 3 QUIET COMPONENTS Graphics Window System)
#Download dependencies
add_subdirectory(ext)

target_link_libraries(PingPong PRIVATE SFML::Graphics)


