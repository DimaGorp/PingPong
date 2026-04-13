#pragma once
#include <Core/Instance/Instance.hpp>
#include <Core/Scene/Scene.hpp>
#include <SFML/Graphics.hpp>
#include <functional>
class GameInstance : public Instance<GameInstance> {
    friend class Instance<GameInstance>;

   private:
    std::function<Scene()> m_sceneFactory;
    GameInstance() = default;
    ~GameInstance() = default;
    Scene m_currentScene;

   public:
    void runGame(sf::RenderWindow& window);
    void setScene(const Scene& scene);
    Scene getScene();
    void setSceneFactory(std::function<Scene()> factory);
    void resetGame();
};