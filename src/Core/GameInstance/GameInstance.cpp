#include <GameInstance/GameInstance.hpp>
#include <Controller/Controller.hpp>

void GameInstance::runGame(sf::RenderWindow& window) {
    Controller& m_controller = Controller::getInstance();
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            m_controller.handleEvents(*event);
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        window.clear();
        window.display();
    }
}