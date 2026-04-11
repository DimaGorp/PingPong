#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

enum class CollisionLayer {
    None,
    Border,
    Player,
    Ball
};
class Actor {
private:
    friend class Renderer;
    friend class CollisionManager;
    std::variant<sf::RectangleShape, sf::CircleShape, sf::ConvexShape, sf::Sprite> m_drawable;


    sf::FloatRect getBounds() const;
    bool intersects(const Actor& other) const;
protected:
    sf::Vector2f m_position;
    sf::Vector2f m_previousPosition;
    sf::Vector2f m_scale;
    void revertLocation();
    Actor(){
        m_drawable = sf::RectangleShape();
        m_previousPosition = {0.f, 0.f};
        m_position = {0.f, 0.f};
        m_scale = {1.f, 1.f};
    };
    CollisionLayer m_collisionLayer = CollisionLayer::None;
public:
    std::function<void(Actor*)> onCollision;
    template<typename T = Actor>
    static T* create() { return new T(); }
    Actor(const Actor&) = delete;
    Actor& operator=(const Actor&) = delete;
    ~Actor() = default;
    sf::Vector2f getActorLocation();
    Actor* setActorLocation(const sf::Vector2f& position);
    Actor* setActorScale(const sf::Vector2f& scale);
    Actor* setShape(std::variant<sf::RectangleShape, sf::CircleShape, sf::ConvexShape, sf::Sprite> drawable);
    Actor* setCollisionLayer(CollisionLayer layer) {
        m_collisionLayer = layer;
        return this;
    }
    CollisionLayer getCollisionLayer() const { return m_collisionLayer; }
};