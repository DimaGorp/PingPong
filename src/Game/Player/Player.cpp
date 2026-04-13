#include <Game/Player/Player.hpp>
#include <Core/Controller/Controller.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <Core/Movement/Components/MovementComponents.hpp>
#include <iostream>
Player::Player(Actor::Private p):Pawn(300.f,p){
    sf::RectangleShape shape({25.f, 250.f});
    shape.setFillColor(sf::Color::Green);
    applyShape(shape);

}
std::shared_ptr<Player> Player::init() {
    auto self = std::static_pointer_cast<Player>(shared_from_this());
    Controller::getInstance().bindEvent(self, &Player::MoveUp,
        sf::Event::KeyPressed{.code = sf::Keyboard::Key::W});
    Controller::getInstance().bindEvent(self, &Player::MoveUp,
        sf::Event::KeyReleased{.code = sf::Keyboard::Key::W});
    Controller::getInstance().bindEvent(self, &Player::MoveDown,
        sf::Event::KeyPressed{.code = sf::Keyboard::Key::S});
    Controller::getInstance().bindEvent(self, &Player::MoveDown,
        sf::Event::KeyReleased{.code = sf::Keyboard::Key::S});
    return self;
}
void Player::MoveUp(const int& value) {
    m_inputDirection.y = (value == 1) ? -1.f : 0.f;
}

void Player::MoveDown(const int& value) {
    m_inputDirection.y = (value == 1) ? 1.f : 0.f;
}

void Player::update(float deltaTime) {
    if (m_inputDirection.y != 0.f)
        m_movement->addMovementInput(m_inputDirection);
    Pawn::update(deltaTime);
}