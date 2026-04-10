#include <SFML/Graphics.hpp>
#include <Core/GameInstance/GameInstance.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Ping Pong");
    GameInstance::getInstance().runGame(window);
    return 0;
}