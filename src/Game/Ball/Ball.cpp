#include <Ball/Ball.hpp>
#include <Core/GameInstance/GameInstance.hpp>

Ball::Ball(Actor::Private p) : Actor{p} {
    sf::CircleShape circle = sf::CircleShape(5.f);
    circle.setFillColor(sf::Color::Blue);
    applyShape(circle);

    // Set initial diagonal velocity — safe to call from constructor
    applyVelocity({300.f, 300.f});

    onCollision = [this](std::shared_ptr<Actor> other) {
        // Ball entered a goal — reset the game
        if (other->getCollisionLayer() == CollisionLayer::Goal) {
            GameInstance::getInstance().resetGame();
            return;
        }

        sf::Vector2f vel = getVelocity();
        sf::Vector2f otherCenter = other->getCenter();
        sf::Vector2f otherSize = other->getSize();

        // Use previous position to determine which side was hit
        sf::Vector2f prevCenter = m_previousPosition + sf::Vector2f(5.f, 5.f);

        // Calculate penetration depth on each axis
        float overlapX = (otherSize.x / 2.f) - std::abs(prevCenter.x - otherCenter.x);
        float overlapY = (otherSize.y / 2.f) - std::abs(prevCenter.y - otherCenter.y);

        // Reflect along the axis with less overlap (the side that was hit)
        if (overlapX < overlapY)
            vel.x = -vel.x;
        else
            vel.y = -vel.y;

        setVelocity(vel);
        revertLocation();

        // Nudge ball out of the collider to prevent sticking
        setActorLocation(m_previousPosition + vel * (1.f / 60.f));
    };
}

void Ball::update(float deltaTime) { Actor::update(deltaTime); }