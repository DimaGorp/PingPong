#pragma once
#include <map>
#include <functional>
#include <Instance/Instance.hpp>
//forward declaration
namespace sf {
    class Event;
}
class Controller: public Instance<Controller>{
            friend class Instance<Controller>;
            friend class GameInstance;
            Controller() = default;
            ~Controller() = default;

            void handleEvents(const sf::Event& event);
        protected:
            //std::map<sf::Event, std::function<void(const int&)>> eventHandlers;
        public:

};