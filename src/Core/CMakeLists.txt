add_library(Core)

if(CMAKE_VERSION VERSION_LESS "3.20")
    set_target_properties(Core PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
    )
else()
    target_compile_features(Core PRIVATE cxx_std_23)
endif()

target_sources(Core PRIVATE 
    ${SOURCE_DIR}/Core/GameInstance/GameInstance.cpp
    ${SOURCE_DIR}/Core/Controller/Controller.cpp
    ${SOURCE_DIR}/Core/Renderer/Renderer.cpp
    ${SOURCE_DIR}/Core/Scene/Scene.cpp
    ${SOURCE_DIR}/Core/Collision/CollisionManager.cpp
)

message(STATUS "Core dir: ${CORE_DIR}")

target_include_directories(Core
    PRIVATE ${CORE_DIR}
    PUBLIC ${INCLUDE_DIR}
)

target_link_libraries(Core PRIVATE SFML::Graphics)