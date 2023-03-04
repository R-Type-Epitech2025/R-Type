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
        quint32 identity;
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
            void update(rtype::SceneManager *currentScene);
            void destroy(SceneManager&);
            void loadEntity();
            void unloadEntity();
            void createNewEvent(quint32 identity, SceneManager *scene, std::string newId, bool newScene, EventSystemType type, sf::Keyboard::Key key);
        protected:
        private:
            std::vector<NewEventComponent_t*> _newEvent;
    };
};

#endif /* !EVENTSYSTEM_HPP_ */