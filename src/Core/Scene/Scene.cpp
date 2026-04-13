#include <Game/Core/Actor/Actor.hpp>
#include <Scene/Scene.hpp>

std::shared_ptr<Actor> Scene::findByLayer(CollisionLayer layer) const {
    // Return the first actor matching the given collision layer
    for (auto actor : Actors) {
        if (actor->getCollisionLayer() == layer) return actor;
    }

    // No actor found on the given layer
    return nullptr;
}