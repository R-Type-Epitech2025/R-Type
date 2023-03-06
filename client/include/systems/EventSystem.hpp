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
    class EventSystem : public QObject {

        Q_OBJECT

        public:
            /**
             ** @brief Construct a new Event System object
             ** 
             ** @param parent 
             */
            EventSystem(QObject *parent = nullptr);

            /**
             ** @brief Destroy the Event System object
             ** 
             */
            ~EventSystem();

            /**
             ** @brief init the event system
             ** 
             ** @param scene 
             */
            void init(SceneManager&);

            /**
             ** @brief update the event system
             ** 
             ** @param scene 
             ** @param event 
             */
            void update(SceneManager *currentScene, sf::Event &event);

            /**
             ** @brief destroy the event system
             ** 
             ** @param scene 
             */
            void destroy(SceneManager&);

            /**
             ** @brief load the entity
             ** 
             */
            void loadEntity();

            /**
             ** @brief unload the entity
             ** 
             */
            void unloadEntity();

            /**
             ** @brief create a new event
             ** 
             ** @param identity 
             ** @param scene 
             ** @param newId 
             ** @param newScene 
             ** @param type 
             ** @param key 
             */
            void createNewEvent(quint32 entityId, std::string newSceneName, std::string sceneName, std::string eventName);

            bool getCollision(Entity *entity, Entity *collideEntity) const;
            std::string _connectInfos;
        protected:
        private:
            std::vector<NewEvent_t*> _eventsList;
            sf::RenderWindow _window;
            // EventComponent _entity;
        signals:
            void shoot();
    };
};

#endif /* !EVENTSYSTEM_HPP_ */