#pragma once
#include <vector>
namespace sf {
    class Drawable;
}
class Actor;
class Scene
{
private:
    friend class Renderer;
    friend class CollisionManager;
    std::vector<Actor*> Actors;
public:
    Scene(std::initializer_list<Actor*> actors = {}) : Actors(actors) {}
    ~Scene() = default;
};