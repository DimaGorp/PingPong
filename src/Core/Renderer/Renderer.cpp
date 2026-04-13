#include <Game/Core/Actor/Actor.hpp>
#include <Renderer/Renderer.hpp>
#include <SFML/Graphics.hpp>
#include <Scene/Scene.hpp>

void Renderer::render(sf::RenderWindow& window, const Scene& scene) {
    // Virtual resolution — all game coordinates are authored for this size
    static constexpr float VIRTUAL_WIDTH = 1440.f;
    static constexpr float VIRTUAL_HEIGHT = 790.f;

    // Compute the largest uniform scale that fits the real window
    sf::Vector2u winSize = window.getSize();
    float scaleX = winSize.x / VIRTUAL_WIDTH;
    float scaleY = winSize.y / VIRTUAL_HEIGHT;
    float scale = std::min(scaleX, scaleY);

    // Convert to viewport coordinates [0..1] and center it (letterbox)
    float vpW = (VIRTUAL_WIDTH * scale) / winSize.x;
    float vpH = (VIRTUAL_HEIGHT * scale) / winSize.y;
    float vpX = (1.f - vpW) / 2.f;
    float vpY = (1.f - vpH) / 2.f;

    // Apply the view — SFML will scale all draws to fit the virtual resolution
    sf::View view(sf::FloatRect({0.f, 0.f}, {VIRTUAL_WIDTH, VIRTUAL_HEIGHT}));
    view.setViewport(sf::FloatRect({vpX, vpY}, {vpW, vpH}));
    window.setView(view);

    // Fill the window with black (visible as letterbox bars if aspect ratios differ)
    window.clear(sf::Color::Black);

    // Draw each actor's drawable variant to the window
    for (auto& actor : scene.Actors) {
        std::visit([&window](const auto& shape) { window.draw(shape); }, actor->m_drawable);
    }

    window.display();
}