#pragma once
#include <Game/Core/Pawn/Pawn.hpp>
#include <SFML/Graphics.hpp>
class Player : public Pawn {
   public:
    explicit Player(Actor::Private p = Private{});
    ~Player() = default;
    std::shared_ptr<Player> init();

   private:
    sf::Vector2f m_inputDirection{0.f, 0.f};
    void update(float deltaTime);
    void MoveUp(const int& value);
    void MoveDown(const int& value);
};