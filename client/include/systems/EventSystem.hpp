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
    /**
     * @brief enum that contains all the type of event
     * 
     */
    enum class EventSystemType {
        COLLISION,
        CHANGESCENE,
        SHOOT,
        MOVE
    };

    /**
     * @brief struct that contains all the information about the event
     * 
     */
    typedef struct NewEventComponent{
        std::string identity;
        sf::Event event;
        sf::Keyboard::Key key;
        SceneManager *scene;
        std::string newId;
        bool newScene;
        EventSystemType type;
    } NewEventComponent_t;

    class EventSystem : public QObject {

        Q_OBJECT

        public:
            /**
             * @brief Construct a new Event System object
             * 
             * @param parent 
             */
            EventSystem(QObject *parent = nullptr);

            /**
             * @brief Destroy the Event System object
             * 
             */
            ~EventSystem();

            /**
             * @brief init the event system
             * 
             * @param scene 
             */
            void init(SceneManager&);

            /**
             * @brief update the event system
             * 
             * @param scene 
             * @param event 
             */
            void update(rtype::SceneManager *currentScene, sf::Event &event);

            /**
             * @brief destroy the event system
             * 
             * @param scene 
             */
            void destroy(SceneManager&);

            /**
             * @brief load the entity
             * 
             */
            void loadEntity();

            /**
             * @brief unload the entity
             * 
             */
            void unloadEntity();

            /**
             * @brief create a new event
             * 
             * @param identity 
             * @param scene 
             * @param newId 
             * @param newScene 
             * @param type 
             * @param key 
             */
            void createNewEvent(std::string identity, SceneManager *scene, std::string newId, bool newScene, EventSystemType type, sf::Keyboard::Key key);
        protected:
        private:
            std::vector<NewEventComponent_t*> _newEvent;
            sf::RenderWindow _window;
            // EventComponent _entity;
        signals:
            void shoot();
    };
};

#endif /* !EVENTSYSTEM_HPP_ */