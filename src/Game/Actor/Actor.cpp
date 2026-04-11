#include <Actor/Actor.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

sf::Vector2f Actor::getActorLocation(){
    std::cout << "getActorLocation: " << m_position.x << " " << m_position.y << std::endl;
    return m_position;
};
Actor* Actor::setActorLocation(const sf::Vector2f& position) {
    std::cout << "setActorLocation: " << position.x << " " << position.y << std::endl;
    m_previousPosition = m_position;
    m_position = position;
     std::visit([&position](auto& shape) {
        shape.setPosition(position);
    }, m_drawable);
    return this;
}
Actor* Actor::setActorScale(const sf::Vector2f& scale) {
    m_scale = scale;
    std::visit([&scale](auto& shape) {
        shape.setScale(scale);
    }, m_drawable);
    return this;
}
Actor* Actor::setShape(std::variant<sf::RectangleShape, sf::CircleShape, sf::ConvexShape, sf::Sprite> drawable) {
    m_drawable = std::move(drawable);
    return this;
}

sf::FloatRect Actor::getBounds() const{
    auto bounds = std::visit([](const auto& shape) -> sf::FloatRect {
        return shape.getGlobalBounds();
    }, m_drawable);
    //std::cout << "bounds: " << bounds.position.x << " " << bounds.position.y << " " << bounds.size.x << " " << bounds.size.y << std::endl;
    return bounds;
}
bool Actor::intersects(const Actor& other) const {
        return getBounds().findIntersection(other.getBounds()).has_value();
}
// Actor.cpp
void Actor::revertLocation() {
    m_position = m_previousPosition;
    std::visit([this](auto& shape) {
        shape.setPosition(m_previousPosition);
    }, m_drawable);
}