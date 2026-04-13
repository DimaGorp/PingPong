#include <Controller/Controller.hpp>
#include <SFML/Window.hpp>
#include <iostream>

void Controller::handleEvents(const sf::Event& event) {
    auto key = makeKey(event);

    // value = 1 for press events, 0 for release events
    int value = 0;
    if (event.is<sf::Event::KeyPressed>() || event.is<sf::Event::MouseButtonPressed>()) value = 1;

    // Invoke all callbacks registered for this event key
    auto [begin, end] = eventQueue.equal_range(key);
    for (auto it = begin; it != end; ++it) {
        it->second(value);
    }
}