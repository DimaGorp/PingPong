#include <Window/Window.hpp>
#include <iostream>

Window* Window::s_instance = nullptr;

Window::Window():sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Ping Pong") {}

Window* Window::getInstance() {
    if (!s_instance) {
        s_instance = new Window();
    }
    return s_instance;
}

void Window::onResize() {
    std::cout << "Window resized: " << getSize().x << "x" << getSize().y << std::endl;
}