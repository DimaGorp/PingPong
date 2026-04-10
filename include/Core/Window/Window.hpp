#pragma once
#include <SFML/Graphics.hpp>
class GameInstance;
class Window: private sf::RenderWindow {
    protected:
        void onCreate() override;
        void onResize() override;
        static Window* getInstance();
    private: 
        static Window* s_instance;
        Window();
    public:
        Window(const Window&) = delete;
        Window& operator=(const Window&) = delete;
        friend class GameInstance;
};
