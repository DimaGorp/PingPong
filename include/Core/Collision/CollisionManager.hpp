#pragma once
#include <Core/Instance/Instance.hpp>
#include <functional>

class Actor;
class Scene;

// Detects and resolves collisions between actors in the scene.
class CollisionManager : public Instance<CollisionManager> {
    friend class Instance<CollisionManager>;
    CollisionManager() = default;
    ~CollisionManager() = default;

   public:
    // Iterates over all actor pairs and triggers onCollision callbacks for intersecting actors.
    void checkCollisions(const Scene& scene);
};