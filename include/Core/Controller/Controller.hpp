#pragma once
#include <Core/Instance/Instance.hpp>
#include <SFML/Window/Event.hpp>
#include <functional>
#include <map>
#include <typeindex>

class Actor;

// Handles input events and dispatches them to bound callbacks.
class Controller : public Instance<Controller> {
    friend class Instance<Controller>;
    friend class GameInstance;
    Controller() = default;
    ~Controller() = default;

    // Looks up and invokes the callback registered for the given event
    void handleEvents(const sf::Event& event);

    // Removes all registered event bindings
    void clearEvents() { eventQueue.clear(); }

   protected:
    // Key identifying a unique event: (event type, key/button code)
    using EventKey = std::pair<std::type_index, int>;

    // Extracts an EventKey from an sf::Event
    static EventKey makeKey(const sf::Event& event) {
        return event.visit([](const auto& e) -> EventKey {
            std::type_index type = typeid(e);
            if constexpr (requires { e.code; }) return {type, (int)e.code};
            if constexpr (requires { e.button; }) return {type, (int)e.button};
            return {type, 0};
        });
    }

    // Maps event keys to their registered callbacks
    std::map<EventKey, std::function<void(const int&)>> eventQueue;

   public:
    // Binds an sf::Event trigger to a method on the given object.
    // Uses weak_ptr to avoid keeping the object alive after it's destroyed.
    template <class T = Actor>
    void bindEvent(std::shared_ptr<T> object, void (T::*method)(const int&), sf::Event trigger) {
        std::weak_ptr<T> weak = object;
        eventQueue.insert({makeKey(trigger), [weak, method](const int& val) {
                               if (auto obj = weak.lock()) (obj.get()->*method)(val);
                           }});
    }
};