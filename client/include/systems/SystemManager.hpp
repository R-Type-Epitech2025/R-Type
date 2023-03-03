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

            void gameQuit();

        protected:
        private:
            GraphicSystem *_graphicSystem;
            MovementSystem *_movementSystem;
            NetworkSystem *_networkSystem;
    };
}

#endif /* !SYSTEMMANAGER_HPP_ */
