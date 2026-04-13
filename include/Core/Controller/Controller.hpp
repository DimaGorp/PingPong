#pragma once
#include <map>
#include <functional>
#include <Core/Instance/Instance.hpp>
#include <SFML/Window/Event.hpp>
#include <typeindex>

class Actor;
class Controller: public Instance<Controller>{
        friend class Instance<Controller>;
        friend class GameInstance;
        Controller() = default;
        ~Controller() = default;
        void handleEvents(const sf::Event& event);
        void clearEvents() { eventQueue.clear(); }
    protected:
        using EventKey = std::pair<std::type_index, int>;
        static EventKey makeKey(const sf::Event& event) {
            return event.visit([](const auto& e) -> EventKey {
                std::type_index type = typeid(e);
                if constexpr (requires { e.code; }) return {type, (int)e.code};
                if constexpr (requires { e.button; }) return {type, (int)e.button};
                return {type, 0};
            });
        }
        std::map<EventKey, std::function<void(const int&)>> eventQueue;
    public:
        template<class T = Actor>
        void bindEvent(
            std::shared_ptr<T> object,
            void(T::*method)(const int&),
            sf::Event trigger
        )
        {
            std::weak_ptr<T> weak = object;
            eventQueue.insert({
                makeKey(trigger),
                [weak, method](const int& val) {
                    if (auto obj = weak.lock())
                        (obj.get()->*method)(val);
                }
            });
        }
};
