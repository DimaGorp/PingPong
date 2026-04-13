#pragma once
#include <Game/Core/Actor/Actor.hpp>
#include <Game/Core/Movement/Components/MovementComponents.hpp>

// Base class for controllable actors with movement support.
// Reverts position on collision by default.
class Pawn : public Actor {
   protected:
    // Handles movement input and velocity application
    std::unique_ptr<MovementComponent> m_movement;

   public:
    explicit Pawn(float speed = 300.0f, Actor::Private p = Actor::Private{});

    // Consumes movement input and updates position
    void update(float deltaTime) override;
};