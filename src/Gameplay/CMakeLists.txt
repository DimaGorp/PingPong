add_library(Gameplay)

target_sources(Gameplay PRIVATE 
    ${SOURCE_DIR}/Gameplay/Actor/Actor.cpp
)
target_include_directories(
    Gameplay
    PRIVATE
    ${GAMEPLAY_DIR}
)
target_link_libraries(Gameplay PRIVATE SFML::Graphics)