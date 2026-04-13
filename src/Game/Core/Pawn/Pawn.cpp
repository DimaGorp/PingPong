#include <Core/Pawn/Pawn.hpp>
#include <iostream>

Pawn::Pawn(float speed, Actor::Private p) : Actor(p) {
    // On collision — revert to previous position to prevent overlap
    onCollision = [this](std::shared_ptr<Actor> other) { revertLocation(); };

    m_movement = std::make_unique<MovementComponent>(this, speed);
}

void Pawn::update(float deltaTime) {
    // Apply accumulated input before updating position
    m_movement->consumeInput();
    Actor::update(deltaTime);
}