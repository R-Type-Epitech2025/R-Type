/*
** EPITECH PROJECT, 2023
** client
** File description:
** EventSystem
*/

#ifndef EVENTSYSTEM_HPP_
#define EVENTSYSTEM_HPP_


#include "ISystem.hpp"
#include <vector>

namespace rtype{
    enum class EventSystemType {
        COLLISION,
        CHANGESCENE,
        SHOOT,
        MOVE
    };

    typedef struct NewEventComponent{
        std::string identity;
        sf::Event event;
        sf::Keyboard::Key key;
        SceneManager *scene;
        std::string newId;
        bool newScene;
        EventSystemType type;
    } NewEventComponent_t;

    class EventSystem{
        public:
            EventSystem();
            ~EventSystem();
            void init(SceneManager&);
            void update(rtype::SceneManager *currentScene, sf::RenderWindow &window, sf::Event &event);
            void destroy(SceneManager&);
            void loadEntity();
            void unloadEntity();
            void createNewEvent(std::string identity, SceneManager *scene, std::string newId, bool newScene, EventSystemType type, sf::Keyboard::Key key);
        protected:
        private:
            std::vector<NewEventComponent_t*> _newEvent;
            sf::RenderWindow _window;
    };
};

#endif /* !EVENTSYSTEM_HPP_ */