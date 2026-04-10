#pragma once
#include <Instance/Instance.hpp>
#include <SFML/Graphics.hpp>

class GameInstance : public Instance<GameInstance> {
    friend class Instance<GameInstance>;
private:
    GameInstance() = default;
    ~GameInstance() = default;
public:
    void runGame(sf::RenderWindow& window);
};