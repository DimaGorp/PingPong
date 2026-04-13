#pragma once
#include <Core/Instance/Instance.hpp>

namespace sf {
class RenderWindow;
class Drawable;
}  // namespace sf

class Scene;

// Responsible for rendering all actors in the scene to the window.
class Renderer : public Instance<Renderer> {
    friend class Instance<Renderer>;

   private:
    Renderer() = default;
    ~Renderer() = default;

   public:
    // Clears the window, draws all actors in the scene, and displays the result.
    void render(sf::RenderWindow& window, const Scene& scene);
};