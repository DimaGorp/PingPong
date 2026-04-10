add_library(Core)
target_sources(Core PRIVATE 
    ${SOURCE_DIR}/Core/GameInstance/GameInstance.cpp
    ${SOURCE_DIR}/Core/Controller/Controller.cpp
)
message(STATUS "Core dir: ${CORE_DIR}")
target_include_directories(
    Core
    PUBLIC
    ${CORE_DIR}
)
target_link_libraries(Core PRIVATE SFML::Graphics)