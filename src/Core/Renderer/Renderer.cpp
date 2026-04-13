#include <Game/Core/Actor/Actor.hpp>
#include <Renderer/Renderer.hpp>
#include <SFML/Graphics.hpp>
#include <Scene/Scene.hpp>

void Renderer::render(sf::RenderWindow& window, const Scene& scene) {
    window.clear();

    // Draw each actor's drawable variant to the window
    for (auto& actor : scene.Actors) {
        std::visit([&window](const auto& shape) { window.draw(shape); }, actor->m_drawable);
    }

    window.display();
}