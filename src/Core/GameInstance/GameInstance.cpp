#include <Collision/CollisionManager.hpp>
#include <Controller/Controller.hpp>
#include <Game/Core/Actor/Actor.hpp>
#include <GameInstance/GameInstance.hpp>
#include <Renderer/Renderer.hpp>
#include <Scene/Scene.hpp>
#include <iostream>

void GameInstance::runGame(sf::RenderWindow& window) {
    window.setVerticalSyncEnabled(true);
    Controller& m_controller = Controller::getInstance();
    Renderer& m_renderer = Renderer::getInstance();
    sf::Clock clock;
    float deltaTime;

    while (window.isOpen()) {
        // Cap delta time to avoid large jumps on lag spikes
        deltaTime = std::min(clock.restart().asSeconds(), 0.05f);

        // Process window events
        while (const std::optional event = window.pollEvent()) {
            m_controller.handleEvents(*event);
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        // Update all actors
        for (auto actor : m_currentScene.Actors) {
            actor->update(deltaTime);
        }

        // Check and resolve collisions
        CollisionManager::getInstance().checkCollisions(m_currentScene);

        // Render the current frame
        m_renderer.render(window, m_currentScene);
    }
}

// Replaces the current scene with the given one
void GameInstance::setScene(const Scene& scene) { m_currentScene = scene; }

// Returns a copy of the current scene
Scene GameInstance::getScene() { return m_currentScene; }

// Clears all input bindings and recreates the scene from the factory
void GameInstance::resetGame() {
    Controller::getInstance().clearEvents();
    m_currentScene = m_sceneFactory();
}

// Stores the factory and immediately creates the initial scene
void GameInstance::setSceneFactory(std::function<Scene()> factory) {
    m_sceneFactory = factory;
    resetGame();
}