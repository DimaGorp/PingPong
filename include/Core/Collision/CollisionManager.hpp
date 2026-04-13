// CollisionManager.hpp
#pragma once
#include <Core/Instance/Instance.hpp>
#include <functional>

class Actor;
class Scene;

class CollisionManager : public Instance<CollisionManager> {
    friend class Instance<CollisionManager>;
    CollisionManager() = default;
    ~CollisionManager() = default;
public:
    void checkCollisions(const Scene& scene);
};