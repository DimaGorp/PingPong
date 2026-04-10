#include <Controller/Controller.hpp>
#include <SFML/Window.hpp>
#include <iostream>
void Controller::handleEvents(const sf::Event& event) {
    if (const auto* keyPress = event.getIf<sf::Event::KeyPressed>()) {
        std::cout << "Key pressed: " << (int)keyPress->code << std::endl;
    }
    else if (const auto* mouseMove = event.getIf<sf::Event::MouseMoved>()) {
        std::cout << "Mouse: " << mouseMove->position.x << std::endl;
    }
}