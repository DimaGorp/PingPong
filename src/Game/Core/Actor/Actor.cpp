#include <Core/Actor/Actor.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

sf::Vector2f Actor::getActorLocation() { return m_position; };

std::shared_ptr<Actor> Actor::setActorLocation(const sf::Vector2f& position) {
    m_previousPosition = m_position;
    m_position = position;
    std::visit([&position](auto& shape) { shape.setPosition(position); }, m_drawable);
    return shared_from_this();
}

std::shared_ptr<Actor> Actor::setActorScale(const sf::Vector2f& scale) {
    m_scale = scale;
    std::visit([&scale](auto& shape) { shape.setScale(scale); }, m_drawable);
    return shared_from_this();
}

sf::FloatRect Actor::getBounds() const {
    return std::visit([](const auto& shape) -> sf::FloatRect { return shape.getGlobalBounds(); }, m_drawable);
}

// Returns true if the bounding boxes of both actors overlap
bool Actor::intersects(const Actor& other) const {
    return getBounds().findIntersection(other.getBounds()).has_value();
}

// Restores position to where the actor was in the previous frame
void Actor::revertLocation() {
    m_position = m_previousPosition;
    std::visit([this](auto& shape) { shape.setPosition(m_previousPosition); }, m_drawable);
}

std::shared_ptr<Actor> Actor::setCollisionLayer(CollisionLayer layer) {
    m_collisionLayer = layer;
    return shared_from_this();
}

void Actor::update(float deltaTime) {
    m_previousPosition = m_position;
    m_position += m_velocity * deltaTime;
    std::visit([this](auto& shape) { shape.setPosition(m_position); }, m_drawable);
}

// Sets drawable directly without returning shared_ptr — safe to call from constructors
void Actor::applyShape(std::variant<sf::RectangleShape, sf::CircleShape, sf::ConvexShape, sf::Sprite> drawable) {
    m_drawable = std::move(drawable);
}

// Sets velocity directly without returning shared_ptr — safe to call from constructors
void Actor::applyVelocity(const sf::Vector2f& vel) { m_velocity = vel; }

std::shared_ptr<Actor> Actor::setShape(
    std::variant<sf::RectangleShape, sf::CircleShape, sf::ConvexShape, sf::Sprite> drawable) {
    applyShape(std::move(drawable));
    return shared_from_this();
}

std::shared_ptr<Actor> Actor::setVelocity(const sf::Vector2f& vel) {
    applyVelocity(vel);
    return shared_from_this();
}

sf::Vector2f Actor::getCenter() const { return getBounds().getCenter(); }

sf::Vector2f Actor::getSize() const { return getBounds().size; }

std::shared_ptr<Actor> Actor::setColor(const sf::Color& color) {
    std::visit(
        [&color](auto& shape) {
            // sf::Sprite does not support setFillColor
            if constexpr (!std::is_same_v<std::decay_t<decltype(shape)>, sf::Sprite>) shape.setFillColor(color);
        },
        m_drawable);
    return shared_from_this();
}