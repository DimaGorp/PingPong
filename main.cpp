#include <SFML/Graphics.hpp>
#include <Core/GameInstance/GameInstance.hpp>
#include <Core/Scene/Scene.hpp>
#include <Game/Actor/Actor.hpp>
#include <Game/Planner/Planner.hpp>
int main() {
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Ping Pong");
    Scene scene = {
        //Borders
        Actor::create()->setShape(sf::RectangleShape({25.0f,300.0f}))->setActorLocation({0.f, 0.f})->setCollisionLayer(CollisionLayer::Border),
        Actor::create()->setShape(sf::RectangleShape({25.0f,300.0f}))->setActorLocation({0.f, 500.f})->setCollisionLayer(CollisionLayer::Border),
        Actor::create()->setShape(sf::RectangleShape({25.0f,300.0f}))->setActorLocation({1415.f, 0.f})->setCollisionLayer(CollisionLayer::Border),
        Actor::create()->setShape(sf::RectangleShape({25.0f,300.0f}))->setActorLocation({1415.f, 500.f})->setCollisionLayer(CollisionLayer::Border),
        Actor::create()->setShape(sf::RectangleShape({1415.f,25.0f}))->setActorLocation({25.f, 0.f})->setCollisionLayer(CollisionLayer::Border),
        Actor::create()->setShape(sf::RectangleShape({1415.f,25.0f}))->setActorLocation({25.f, 770.f})->setCollisionLayer(CollisionLayer::Border),

        Actor::create<Planner>()->setActorLocation({100.f, 300.f})->setCollisionLayer(CollisionLayer::Player)
    };
    GameInstance& game = GameInstance::getInstance();
    game.setScene(scene);
    game.runGame(window);
    return 0;
}