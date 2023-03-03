/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** SystemManager
*/

#ifndef SYSTEMMANAGER_HPP_
#define SYSTEMMANAGER_HPP_

#include "ISystem.hpp"
#include "GraphicSystem.hpp"
#include "MovementSystem.hpp"
#include "NetworkSystem.hpp"
#include "EventSystem.hpp"

namespace rtype {

    class SystemManager : public QObject {

        Q_OBJECT
    
        public:
            SystemManager(QObject *parent = nullptr);
            ~SystemManager();

            void createGraphicSystem();
            void createMovementSystem();
            void createNetworkSystem(QString addr, quint32 port);
            void createEventSystem();

            void updateEvents(SceneManager *currentScene, sf::Event &event);
            void updateGraphic(SceneManager *Manager, uint64_t time);
            void updateMovement(SceneManager *Manager, sf::Event &event);

            void gameQuit();

            GraphicSystem *graphicSystem;
            MovementSystem *movementSystem;
            NetworkSystem *networkSystem;
            EventSystem *eventSystem;
        protected:
        private:
    };
}

#endif /* !SYSTEMMANAGER_HPP_ */
