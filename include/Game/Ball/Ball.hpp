#include "Game/Core/Actor/Actor.hpp"

// A ball actor that bounces off walls and paddles.
// Triggers a game reset when it enters a goal zone.
class Ball : public Actor {
   public:
    explicit Ball(Actor::Private p = Private{});

    // Updates position and handles bounce logic via onCollision
    void update(float deltaTime) override;
};