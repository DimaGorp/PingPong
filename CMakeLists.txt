cmake_minimum_required(VERSION 3.10)
project(PingPong)

set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

add_executable(PingPong main.cpp)

if(CMAKE_VERSION VERSION_LESS "3.20")
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
else()
    target_compile_features(PingPong PRIVATE cxx_std_23)
endif()

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