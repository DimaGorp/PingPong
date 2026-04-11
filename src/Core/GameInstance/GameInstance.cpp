#include <GameInstance/GameInstance.hpp>
#include <Controller/Controller.hpp>
#include <Renderer/Renderer.hpp>
#include <Scene/Scene.hpp>
#include <Collision/CollisionManager.hpp>
void GameInstance::runGame(sf::RenderWindow& window) {

    Controller& m_controller = Controller::getInstance();
    Renderer& m_renderer = Renderer::getInstance();

    while (window.isOpen()) {
        CollisionManager::getInstance().checkCollisions(*m_currentScene);
        while (const std::optional event = window.pollEvent()) {
            m_controller.handleEvents(*event);
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        CollisionManager::getInstance().checkCollisions(m_currentScene ? *m_currentScene : Scene());
        m_renderer.render(window, m_currentScene ? *m_currentScene : Scene());
    }
}

void GameInstance::setScene(const Scene& scene){
    m_currentScene = &scene;
}