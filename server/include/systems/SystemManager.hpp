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

    class SystemManager {
        public:
            SystemManager();
            ~SystemManager();

            void setGraphicSystem(GraphicSystem *graphicSystem);
            void setMovementSystem(MovementSystem *movementSystem);
            void setNetworkSystem(NetworkSystem *networkSystem);

        protected:
        private:
            GraphicSystem *_graphicSystem;
            MovementSystem *_movementSystem;
            NetworkSystem *_networkSystem;
    };
}

#endif /* !SYSTEMMANAGER_HPP_ */
