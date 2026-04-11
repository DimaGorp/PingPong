#pragma once
#include <Core/Instance/Instance.hpp>
#include <SFML/Graphics.hpp>
class Scene;
class GameInstance : public Instance<GameInstance> {
    friend class Instance<GameInstance>;
private:
    GameInstance() = default;
    ~GameInstance() = default;
    const Scene* m_currentScene = nullptr;
public:
    void runGame(sf::RenderWindow& window);
    void setScene(const Scene& scene);
};