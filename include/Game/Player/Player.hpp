#pragma once
#include <Game/Core/Pawn/Pawn.hpp>
#include <SFML/Graphics.hpp>

// Human-controlled player. Binds keyboard input to movement.
class Player : public Pawn {
   public:
    explicit Player(Actor::Private p = Private{});
    ~Player() = default;

    // Binds keyboard events to movement methods.
    // Must be called after construction since it uses shared_from_this().
    std::shared_ptr<Player> init();

   private:
    // Current input direction accumulated from key events
    sf::Vector2f m_inputDirection{0.f, 0.f};

    void update(float deltaTime) override;

    // Called on W key press/release — sets vertical input to -1 or 0
    void MoveUp(const int& value);

    // Called on S key press/release — sets vertical input to 1 or 0
    void MoveDown(const int& value);
};