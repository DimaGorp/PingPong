#pragma once
#include <Game/Core/Pawn/Pawn.hpp>

class AIPlayer : public Pawn {
   public:
    explicit AIPlayer(Actor::Private p = Actor::Private{});
    void update(float deltaTime) override;
    std::shared_ptr<AIPlayer> setReactionDelay(float reactionDelay);
    std::shared_ptr<AIPlayer> setErrorRange(float errorRange);
    std::shared_ptr<AIPlayer> setDeadZone(float deadZone);

   private:
    float m_reactionDelay = 0.4f;
    float m_errorRange = 30.f;
    float m_deadZone = 20.f;
    float m_reactionTimer = 0.f;
    float m_targetY = 0.f;
};