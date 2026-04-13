add_library(Game)
if(CMAKE_VERSION VERSION_GREATER_EQUAL "3.20")
    target_compile_features(Game PRIVATE cxx_std_23)
else()
    set_target_properties(Game PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
    )
endif()
target_sources(Game PRIVATE 
    ${SOURCE_DIR}/Game/Ball/Ball.cpp
    ${SOURCE_DIR}/Game/Player/Player.cpp
    ${SOURCE_DIR}/Game/Player/AIPlayer.cpp
    ${SOURCE_DIR}/Game/Core/Movement/Components/MovementComponent.cpp
    ${SOURCE_DIR}/Game/Core/Pawn/Pawn.cpp
    ${SOURCE_DIR}/Game/Core/Actor/Actor.cpp
    
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
