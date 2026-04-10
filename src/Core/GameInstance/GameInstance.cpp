#include <GameInstance/GameInstance.hpp>
#include <Window/Window.hpp>
GameInstance* GameInstance::s_instance = nullptr;

GameInstance* GameInstance::getInstance() {
    if (!s_instance) {
        s_instance = new GameInstance();
    }
    return s_instance;
}

GameInstance::GameInstance() {
    m_window = Window::getInstance();
    runGame();
}
void GameInstance::runGame() {
    while (m_window->isOpen())
    {
        while(const std::optional event = m_window->pollEvent()) {
            if (event->is<sf::Event::Closed>())
                m_window->close();
        }
        m_window->clear();
        m_window->display();
    }
}