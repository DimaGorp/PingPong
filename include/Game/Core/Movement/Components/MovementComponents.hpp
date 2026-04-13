#pragma once
#include <Game/Core/Actor/Actor.hpp>

class Pawn;

// Handles movement logic for a Pawn.
// Accumulates input each frame and applies it as velocity on consumeInput().
class MovementComponent {
    friend class Pawn;

    Actor* m_owner;          // Raw pointer — does not own the actor
    float m_speed;           // Movement speed in pixels per second
    sf::Vector2f m_inputVector;  // Accumulated input direction for the current frame

    // Applies accumulated input as velocity and resets it
    void consumeInput();

   public:
    MovementComponent(Actor* owner, float speed) : m_owner(owner), m_speed(speed), m_inputVector({0.f, 0.f}) {}

    // Adds a direction to the input vector for this frame
    void addMovementInput(const sf::Vector2f& direction);
};