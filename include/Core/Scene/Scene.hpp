#pragma once
#include <memory>
#include <vector>

namespace sf {
class Drawable;
}

enum class CollisionLayer;
class Actor;

// Holds all actors in the current game state.
class Scene {
   private:
    friend class Renderer;
    friend class GameInstance;
    friend class CollisionManager;

    // All actors present in the scene
    std::vector<std::shared_ptr<Actor>> Actors;

   public:
    // Constructs a scene from an initializer list of actors
    Scene(std::initializer_list<std::shared_ptr<Actor>> actors = {}) : Actors(actors) {}
    ~Scene() = default;

    // Returns the first actor found on the given collision layer, or nullptr
    std::shared_ptr<Actor> findByLayer(CollisionLayer layer) const;
};