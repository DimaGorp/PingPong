#include <Ball/Ball.hpp>
#include <Core/GameInstance/GameInstance.hpp>
Ball::Ball(Actor::Private p):Actor{p} {
    sf::CircleShape circle = sf::CircleShape(5.f);
    circle.setFillColor(sf::Color::Blue);
    applyShape(circle);
    applyVelocity({300.f, 300.f});
    onCollision = [this](std::shared_ptr<Actor> other) {
        if (other->getCollisionLayer() == CollisionLayer::Goal) {
            GameInstance::getInstance().resetGame();
            return;
        }
        sf::Vector2f vel = getVelocity();

        sf::Vector2f otherCenter = other->getCenter();
        sf::Vector2f otherSize   = other->getSize();

        sf::Vector2f prevCenter = m_previousPosition + sf::Vector2f(5.f, 5.f);


        float overlapX = (otherSize.x / 2.f) - std::abs(prevCenter.x - otherCenter.x);
        float overlapY = (otherSize.y / 2.f) - std::abs(prevCenter.y - otherCenter.y);

        if (overlapX < overlapY) vel.x = -vel.x;
        else                     vel.y = -vel.y;

        setVelocity(vel);
        revertLocation();
        setActorLocation(m_previousPosition + vel * (1.f / 60.f));
    };
}

void Ball::update(float deltaTime){
    Actor::update(deltaTime);
} 