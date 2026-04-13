#include <Core/GameInstance/GameInstance.hpp>
#include <Core/Scene/Scene.hpp>
#include <Game/Ball/Ball.hpp>
#include <Game/Core/Actor/Actor.hpp>
#include <Game/Player/AIPlayer.hpp>
#include <Game/Player/Player.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
int main() {
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Ping Pong");
    sf::Vector2u winSize = window.getSize();
    std::cout << winSize.x << "x" << winSize.y << std::endl;
    // Factory function — called on startup and on every game reset
    auto createScene = []() -> Scene {
        return {
            // Borders — top-left, bottom-left, top-right, bottom-right corners + top/bottom walls
            Actor::create()
                ->setShape(sf::RectangleShape({25.f, 300.f}))
                ->setActorLocation({0.f, 0.f})
                ->setCollisionLayer(CollisionLayer::Border),
            Actor::create()
                ->setShape(sf::RectangleShape({25.f, 300.f}))
                ->setActorLocation({0.f, 500.f})
                ->setCollisionLayer(CollisionLayer::Border),
            Actor::create()
                ->setShape(sf::RectangleShape({25.f, 300.f}))
                ->setActorLocation({1415.f, 0.f})
                ->setCollisionLayer(CollisionLayer::Border),
            Actor::create()
                ->setShape(sf::RectangleShape({25.f, 300.f}))
                ->setActorLocation({1415.f, 500.f})
                ->setCollisionLayer(CollisionLayer::Border),
            Actor::create()
                ->setShape(sf::RectangleShape({1415.f, 25.f}))
                ->setActorLocation({25.f, 0.f})
                ->setCollisionLayer(CollisionLayer::Border),
            Actor::create()
                ->setShape(sf::RectangleShape({1415.f, 25.f}))
                ->setActorLocation({25.f, 770.f})
                ->setCollisionLayer(CollisionLayer::Border),

            // Goals — left and right scoring zones
            Actor::create()
                ->setShape(sf::RectangleShape({25.f, 200.f}))
                ->setColor(sf::Color::Blue)
                ->setActorLocation({0.f, 300.f})
                ->setCollisionLayer(CollisionLayer::Goal),
            Actor::create()
                ->setShape(sf::RectangleShape({25.f, 200.f}))
                ->setColor(sf::Color::Blue)
                ->setActorLocation({1415.f, 300.f})
                ->setCollisionLayer(CollisionLayer::Goal),

            // Players — human on the left, AI on the right
            Actor::create<Player>()
                ->init()
                ->setActorLocation({100.f, 300.f})
                ->setCollisionLayer(CollisionLayer::Player),
            Actor::create<AIPlayer>()
                ->setDeadZone(40.f)
                ->setErrorRange(80.f)
                ->setReactionDelay(0.6f)
                ->setActorLocation({1300.f, 300.f})
                ->setCollisionLayer(CollisionLayer::Player),

            // Ball — starts on the left side
            Actor::create<Ball>()->setActorLocation({150.f, 300.f})->setCollisionLayer(CollisionLayer::Ball),
        };
    };

    GameInstance& game = GameInstance::getInstance();
    game.setSceneFactory(createScene);
    game.runGame(window);
    return 0;
}