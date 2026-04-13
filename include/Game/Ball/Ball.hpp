#include "Game/Core/Actor/Actor.hpp"
class Ball : public Actor {
   public:
    explicit Ball(Actor::Private p = Private{});
    void update(float deltaTime) override;
};