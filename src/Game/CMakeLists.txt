add_library(Game)
target_compile_features(Game PRIVATE cxx_std_23)
target_sources(Game PRIVATE 
    ${SOURCE_DIR}/Game/Planner/Planner.cpp
    ${SOURCE_DIR}/Game/Actor/Actor.cpp
)
message(STATUS "Game dir: ${GAME_DIR}")
target_include_directories(
    Game
    PRIVATE
    ${GAME_DIR}
    PUBLIC
    ${INCLUDE_DIR}
)
target_link_libraries(Game PRIVATE SFML::Graphics)
