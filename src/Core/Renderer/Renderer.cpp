#include <Renderer/Renderer.hpp>
#include <Scene/Scene.hpp>
#include <SFML/Graphics.hpp>
#include <Game/Actor/Actor.hpp>
void Renderer::render(sf::RenderWindow& window, const Scene& scene) {
    window.clear();
    for (auto& actor : scene.Actors) {
        std::visit([&window](const auto& shape) {
            window.draw(shape);
        }, actor->m_drawable);
    }
    window.display();
}