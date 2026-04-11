#include <Planner/Planner.hpp>
#include <Core/Controller/Controller.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
Planner::Planner():Speed(10.f){
    setSize({25.f,250.f});
    setFillColor(sf::Color::Green);
    setShape(*this);
    onCollision = [this](Actor* other) {
        revertLocation();
    };
    Controller::getInstance().bindEvent(this,&Planner::MoveUp,sf::Event::KeyPressed{.code = sf::Keyboard::Key::W});
    Controller::getInstance().bindEvent(this,&Planner::MoveUp,sf::Event::KeyReleased{.code = sf::Keyboard::Key::W});
    Controller::getInstance().bindEvent(this,&Planner::MoveDown,sf::Event::KeyPressed{.code = sf::Keyboard::Key::S});
    Controller::getInstance().bindEvent(this,&Planner::MoveDown,sf::Event::KeyReleased{.code = sf::Keyboard::Key::S});
}
void Planner::MoveUp(const int& value){
    std::cout << "MoveUp: " << value << std::endl;
    Actor::setActorLocation({Actor::getActorLocation().x, Actor::getActorLocation().y - Speed * value});
}
void Planner::MoveDown(const int& value){
    std::cout << "MoveDown: " << value << std::endl;
    Actor::setActorLocation({Actor::getActorLocation().x, Actor::getActorLocation().y + Speed * value});
}