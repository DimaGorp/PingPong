#include <Game/Core/Actor/Actor.hpp>
#include <Scene/Scene.hpp>
std::shared_ptr<Actor> Scene::findByLayer(CollisionLayer layer) const {
    for (auto actor : Actors) {
        if (actor->getCollisionLayer() == layer) return actor;
    }
    return nullptr;
}