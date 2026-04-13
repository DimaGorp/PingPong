#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

enum class CollisionLayer {
    None,
    Border,
    Player,
    Ball,
    Goal
};
class Actor: public std::enable_shared_from_this<Actor> {
public:
    struct Private { explicit Private() = default; };
    Actor(Private){
        m_drawable = sf::RectangleShape();
        m_previousPosition = {0.f, 0.f};
        m_position = {0.f, 0.f};
        m_scale = {1.f, 1.f};
        m_velocity = {0.f, 0.f};
    };
private:
    friend class Renderer;
    friend class CollisionManager;
    friend class MovementComponent;
    friend class GameInstance;
    std::variant<sf::RectangleShape, sf::CircleShape, sf::ConvexShape, sf::Sprite> m_drawable;
    sf::FloatRect getBounds() const;
    bool intersects(const Actor& other) const;

protected:
    sf::Vector2f m_position;
    sf::Vector2f m_previousPosition;
    sf::Vector2f m_scale;
    sf::Vector2f m_velocity;
    void applyShape(std::variant<sf::RectangleShape, sf::CircleShape, sf::ConvexShape, sf::Sprite> drawable);
    void applyVelocity(const sf::Vector2f& vel);
    void revertLocation();
    CollisionLayer m_collisionLayer = CollisionLayer::None;
    virtual void update(float deltaTime);
    std::shared_ptr<Actor> setVelocity(const sf::Vector2f& vel);
public:

    sf::Vector2f getCenter() const;
    sf::Vector2f getSize() const;
    std::function<void(std::shared_ptr<Actor>)> onCollision;
    template<typename T = Actor>
    static std::shared_ptr<T> create() { return std::make_shared<T>(Private{}); }
    Actor(const Actor&) = delete;
    Actor& operator=(const Actor&) = delete;
    ~Actor() = default;
    sf::Vector2f getActorLocation();
    std::shared_ptr<Actor> setActorLocation(const sf::Vector2f& position);
    std::shared_ptr<Actor> setActorScale(const sf::Vector2f& scale);
    std::shared_ptr<Actor> setShape(std::variant<sf::RectangleShape, sf::CircleShape, sf::ConvexShape, sf::Sprite> drawable);
    std::shared_ptr<Actor> setColor(const sf::Color& color) ;
    std::shared_ptr<Actor> setCollisionLayer(CollisionLayer layer);
    CollisionLayer getCollisionLayer() const { return m_collisionLayer; }
    sf::Vector2f getVelocity() const { return m_velocity; }
};