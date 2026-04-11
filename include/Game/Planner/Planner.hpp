#pragma once
#include <SFML/Graphics.hpp>
#include <Game/Actor/Actor.hpp>
class Planner: public sf::RectangleShape, public Actor
{
public:
    Planner();
    ~Planner() = default;
protected:
    sf::Vector2f Velocity;
    float Speed;
private:
    void MoveUp(const int& value);
    void MoveDown(const int& value);
};