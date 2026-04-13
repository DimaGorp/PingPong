#pragma once
#include <Game/Core/Actor/Actor.hpp>
#include <Game/Core/Movement/Components/MovementComponents.hpp>
class Pawn:public Actor{
    protected:
        std::unique_ptr<MovementComponent> m_movement;
    public:
        explicit Pawn(float speed = 300.0f, Actor::Private p = Actor::Private{});
        void update(float deltaTime) override;
};