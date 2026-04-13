#include <Collision/CollisionManager.hpp>
#include <Scene/Scene.hpp>
#include <Game/Core/Actor/Actor.hpp>
#include <iostream>
void CollisionManager::checkCollisions(const Scene& scene) {
    auto actors = scene.Actors;
    for (size_t i = 0; i < actors.size(); i++) {
        for (size_t j = i + 1; j < actors.size(); j++) {
            if (actors[i]->m_collisionLayer == actors[j]->m_collisionLayer) continue;
            if (actors[i]->m_collisionLayer == CollisionLayer::None) continue;
            if (actors[j]->m_collisionLayer == CollisionLayer::None) continue;
            if (actors[i]->intersects(*actors[j].get())) {
                if (actors[i]->onCollision) actors[i]->onCollision(actors[j]);
                if (actors[j]->onCollision) actors[j]->onCollision(actors[i]);
            }
        }
    }
}