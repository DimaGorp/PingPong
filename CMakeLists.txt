cmake_minimum_required(VERSION 3.20)
project(PingPong)

set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

add_executable(PingPong main.cpp)
target_compile_features(PingPong PRIVATE cxx_std_23)

find_package(SFML 3 QUIET COMPONENTS Graphics Window System)

add_subdirectory(ext)
add_subdirectory(${INCLUDE_DIR})
add_subdirectory(${SOURCE_DIR})

target_link_libraries(PingPong PRIVATE
    SFML::Graphics
    Core
    Game
)
target_include_directories(PingPong PRIVATE
    ${INCLUDE_DIR}
)