#pragma once
#include <Core/Instance/Instance.hpp>
#include <Core/Scene/Scene.hpp>
#include <SFML/Graphics.hpp>
#include <functional>

// Manages the game loop, scene lifecycle, and coordinates all subsystems.
class GameInstance : public Instance<GameInstance> {
    friend class Instance<GameInstance>;

   private:
    std::function<Scene()> m_sceneFactory;  // Factory function to (re)create the scene
    GameInstance() = default;
    ~GameInstance() = default;
    Scene m_currentScene;  // The currently active scene

   public:
    // Starts the main game loop
    void runGame(sf::RenderWindow& window);

    // Replaces the current scene with the given one
    void setScene(const Scene& scene);

    // Returns a copy of the current scene
    Scene getScene();

    // Sets the factory function used to create/reset the scene
    void setSceneFactory(std::function<Scene()> factory);

    // Recreates the scene using the factory function
    void resetGame();
};