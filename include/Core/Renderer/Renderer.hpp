#pragma once
#include <Core/Instance/Instance.hpp>
namespace sf {
class RenderWindow;
class Drawable;
}  // namespace sf
class Scene;
class Renderer : public Instance<Renderer> {
    friend class Instance<Renderer>;

   private:
    Renderer() = default;
    ~Renderer() = default;

   public:
    void render(sf::RenderWindow& window, const Scene& scene);
};