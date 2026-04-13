#pragma once
#include <Game/Core/Actor/Actor.hpp>

class Pawn;

class MovementComponent {
    friend class Pawn;

    Actor* m_owner;
    float m_speed;
    sf::Vector2f m_inputVector;

    void consumeInput();

public:
    MovementComponent(Actor* owner, float speed)
        : m_owner(owner), m_speed(speed), m_inputVector({0.f, 0.f}) {}

    void addMovementInput(const sf::Vector2f& direction);
};