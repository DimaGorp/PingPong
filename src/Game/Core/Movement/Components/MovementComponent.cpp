#include <Core/Movement/Components/MovementComponents.hpp>

void MovementComponent::consumeInput(){
    if (m_inputVector.x != 0.f || m_inputVector.y != 0.f) {
        m_owner->setVelocity(m_inputVector.normalized() * m_speed);
    } else {
        m_owner->setVelocity({0.f, 0.f});
    }
    m_inputVector = {0.f, 0.f};
}
void MovementComponent::addMovementInput(const sf::Vector2f& direction) {
    m_inputVector += direction;
}
