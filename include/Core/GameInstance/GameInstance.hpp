#pragma once

class Window;
class GameInstance {
    private:
        static GameInstance* s_instance;
        Window* m_window;
        GameInstance();
        void runGame();
    public:
        GameInstance(const GameInstance&) = delete;
        GameInstance& operator=(const GameInstance&) = delete;
        static GameInstance* getInstance();
};