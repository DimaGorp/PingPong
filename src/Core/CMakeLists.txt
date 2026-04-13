add_library(Core)
target_compile_features(Core PRIVATE cxx_std_23)
target_sources(Core PRIVATE 
    ${SOURCE_DIR}/Core/GameInstance/GameInstance.cpp
    ${SOURCE_DIR}/Core/Controller/Controller.cpp
    ${SOURCE_DIR}/Core/Renderer/Renderer.cpp
    ${SOURCE_DIR}/Core/Scene/Scene.cpp
    ${SOURCE_DIR}/Core/Collision/CollisionManager.cpp
)
message(STATUS "Core dir: ${CORE_DIR}")
target_include_directories(
    Core
    PRIVATE
    ${CORE_DIR}
    PUBLIC
    ${INCLUDE_DIR}
)
target_link_libraries(Core PRIVATE SFML::Graphics)