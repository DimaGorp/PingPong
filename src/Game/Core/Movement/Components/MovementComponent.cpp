#include <Core/Movement/Components/MovementComponents.hpp>

void MovementComponent::consumeInput() {
    if (m_inputVector.x != 0.f || m_inputVector.y != 0.f) {
        // Normalize direction to prevent faster diagonal movement, then scale by speed
        m_owner->setVelocity(m_inputVector.normalized() * m_speed);
    } else {
        // No input — stop the actor
        m_owner->setVelocity({0.f, 0.f});
    }

    // Reset input for the next frame
    m_inputVector = {0.f, 0.f};
}

// Accumulates direction input — called once per frame before consumeInput()
void MovementComponent::addMovementInput(const sf::Vector2f& direction) { m_inputVector += direction; }