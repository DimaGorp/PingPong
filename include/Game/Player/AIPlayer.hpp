#pragma once
#include <Game/Core/Pawn/Pawn.hpp>

// AI-controlled player. Tracks the ball and moves toward it with configurable behavior.
class AIPlayer : public Pawn {
   public:
    explicit AIPlayer(Actor::Private p = Actor::Private{});
    void update(float deltaTime) override;

    // Sets the delay in seconds between AI target updates
    std::shared_ptr<AIPlayer> setReactionDelay(float reactionDelay);

    // Sets the max random offset applied to the target position
    std::shared_ptr<AIPlayer> setErrorRange(float errorRange);

    // Sets the minimum distance to the target before the AI starts moving
    std::shared_ptr<AIPlayer> setDeadZone(float deadZone);

   private:
    float m_reactionDelay = 0.4f;  // How often the AI updates its target (seconds)
    float m_errorRange = 30.f;     // Max random error added to target Y position
    float m_deadZone = 20.f;       // AI won't move if closer than this to the target
    float m_reactionTimer = 0.f;   // Tracks time since last target update
    float m_targetY = 0.f;         // Current target Y position to move toward
};