#include <Core/GameInstance/GameInstance.hpp>
#include <Core/Movement/Components/MovementComponents.hpp>
#include <Core/Scene/Scene.hpp>
#include <Game/Player/AIPlayer.hpp>

AIPlayer::AIPlayer(Actor::Private p) : Pawn(300.f, p) {
    sf::RectangleShape shape({25.f, 250.f});
    shape.setFillColor(sf::Color::Red);
    applyShape(shape);
}

void AIPlayer::update(float deltaTime) {
    m_reactionTimer += deltaTime;

    // Update target position at intervals defined by m_reactionDelay
    if (m_reactionTimer >= m_reactionDelay) {
        Actor* ball = GameInstance::getInstance().getScene().findByLayer(CollisionLayer::Ball).get();
        if (ball) {
            // Add random error to make AI imperfect
            float error = (std::rand() % (int)(m_errorRange * 2)) - m_errorRange;
            m_targetY = ball->getCenter().y + error;
        }
        m_reactionTimer = 0.f;
    }

    // Move toward target only if outside the dead zone
    float diff = m_targetY - getCenter().y;
    if (std::abs(diff) > m_deadZone) {
        m_movement->addMovementInput({0.f, diff > 0.f ? 1.f : -1.f});
    }

    Pawn::update(deltaTime);
}

std::shared_ptr<AIPlayer> AIPlayer::setReactionDelay(float reactionDelay) {
    m_reactionDelay = reactionDelay;
    return std::static_pointer_cast<AIPlayer>(shared_from_this());
}

std::shared_ptr<AIPlayer> AIPlayer::setErrorRange(float errorRange) {
    m_errorRange = errorRange;
    return std::static_pointer_cast<AIPlayer>(shared_from_this());
}

std::shared_ptr<AIPlayer> AIPlayer::setDeadZone(float deadZone) {
    m_deadZone = deadZone;
    return std::static_pointer_cast<AIPlayer>(shared_from_this());
}