add_library(Core)
target_sources(Core PRIVATE 
    ${SOURCE_DIR}/Core/Window/Window.cpp
    ${SOURCE_DIR}/Core/GameInstance/GameInstance.cpp
)
target_include_directories(
    Core
    PRIVATE
    ${CORE_DIR}
)
target_link_libraries(Core PRIVATE SFML::Graphics)