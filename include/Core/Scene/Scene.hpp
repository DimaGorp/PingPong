#pragma once
#include <vector>
#include <memory>
namespace sf {
    class Drawable;
}
enum class CollisionLayer;
class Actor;
class Scene
{
private:
    friend class Renderer;
    friend class GameInstance;
    friend class CollisionManager;
    std::vector<std::shared_ptr<Actor>> Actors;
public:
    Scene(std::initializer_list<std::shared_ptr<Actor>> actors = {}) : Actors(actors) {}
    ~Scene() = default;
    std::shared_ptr<Actor> findByLayer(CollisionLayer layer) const ;
};