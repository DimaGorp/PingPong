#include <Collision/CollisionManager.hpp>
#include <Game/Core/Actor/Actor.hpp>
#include <Scene/Scene.hpp>
#include <iostream>

void CollisionManager::checkCollisions(const Scene& scene) {
    // Copy the actors vector to avoid issues if the scene is modified during collision callbacks
    auto actors = scene.Actors;

    for (size_t i = 0; i < actors.size(); i++) {
        for (size_t j = i + 1; j < actors.size(); j++) {
            // Skip actors on the same collision layer
            if (actors[i]->m_collisionLayer == actors[j]->m_collisionLayer) continue;

            // Skip actors with no collision layer
            if (actors[i]->m_collisionLayer == CollisionLayer::None) continue;
            if (actors[j]->m_collisionLayer == CollisionLayer::None) continue;

            // Notify both actors if they intersect
            if (actors[i]->intersects(*actors[j].get())) {
                if (actors[i]->onCollision) actors[i]->onCollision(actors[j]);
                if (actors[j]->onCollision) actors[j]->onCollision(actors[i]);
            }
        }
    }
}