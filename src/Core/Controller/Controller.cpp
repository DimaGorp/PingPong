#include <Controller/Controller.hpp>
#include <SFML/Window.hpp>
#include <iostream>
void Controller::handleEvents(const sf::Event& event) {
    auto key = makeKey(event);
    int value = 0;
    if (event.is<sf::Event::KeyPressed>() || event.is<sf::Event::MouseButtonPressed>())
        value = 1;
    auto [begin, end] = eventQueue.equal_range(key);
    for (auto it = begin; it != end; ++it) {
        it->second(value);
    }
}
