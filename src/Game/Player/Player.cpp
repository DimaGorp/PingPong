#include <Core/Controller/Controller.hpp>
#include <Core/Movement/Components/MovementComponents.hpp>
#include <Game/Player/Player.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

Player::Player(Actor::Private p) : Pawn(300.f, p) {
    sf::RectangleShape shape({25.f, 250.f});
    shape.setFillColor(sf::Color::Green);
    applyShape(shape);
}

std::shared_ptr<Player> Player::init() {
    // Cast to derived type since shared_from_this() returns shared_ptr<Actor>
    auto self = std::static_pointer_cast<Player>(shared_from_this());

    // Bind W key press/release to vertical movement
    Controller::getInstance().bindEvent(self, &Player::MoveUp, sf::Event::KeyPressed{.code = sf::Keyboard::Key::W});
    Controller::getInstance().bindEvent(self, &Player::MoveUp, sf::Event::KeyReleased{.code = sf::Keyboard::Key::W});

    // Bind S key press/release to vertical movement
    Controller::getInstance().bindEvent(self, &Player::MoveDown, sf::Event::KeyPressed{.code = sf::Keyboard::Key::S});
    Controller::getInstance().bindEvent(self, &Player::MoveDown, sf::Event::KeyReleased{.code = sf::Keyboard::Key::S});

    return self;
}

// value == 1 on press, 0 on release
void Player::MoveUp(const int& value) { m_inputDirection.y = (value == 1) ? -1.f : 0.f; }

void Player::MoveDown(const int& value) { m_inputDirection.y = (value == 1) ? 1.f : 0.f; }

void Player::update(float deltaTime) {
    // Only pass input to movement component if there is any
    if (m_inputDirection.y != 0.f) m_movement->addMovementInput(m_inputDirection);
    Pawn::update(deltaTime);
}