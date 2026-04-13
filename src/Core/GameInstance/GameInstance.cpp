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
        deltaTime = std::min(clock.restart().asSeconds(), 0.05f);
        while (const std::optional event = window.pollEvent()) {
            m_controller.handleEvents(*event);
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        for (auto actor : m_currentScene.Actors) {
            actor->update(deltaTime);
        }
        CollisionManager::getInstance().checkCollisions(m_currentScene);
        m_renderer.render(window, m_currentScene);
    }
}

void GameInstance::setScene(const Scene& scene) { m_currentScene = scene; }

Scene GameInstance::getScene() { return m_currentScene; }

void GameInstance::resetGame() {
    Controller::getInstance().clearEvents();
    m_currentScene = m_sceneFactory();
}

void GameInstance::setSceneFactory(std::function<Scene()> factory) {
    m_sceneFactory = factory;
    resetGame();
}