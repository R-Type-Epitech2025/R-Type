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
            /**
             ** @brief Construct a new System Manager object
             ** 
             */
            SystemManager();

            /**
             ** @brief Destroy the System Manager object
             ** 
             */
            ~SystemManager();

            /**
             ** @brief Set the Graphic System object
             ** 
             ** @param graphicSystem 
             */
            void setGraphicSystem(GraphicSystem *graphicSystem);

            /**
             ** @brief Set the Movement System object
             ** 
             ** @param movementSystem 
             */
            void setMovementSystem(MovementSystem *movementSystem);

            /**
             ** @brief Set the Network System object
             ** 
             ** @param networkSystem 
             */
            void setNetworkSystem(NetworkSystem *networkSystem);

        protected:
        private:
            GraphicSystem *_graphicSystem;
            MovementSystem *_movementSystem;
            NetworkSystem *_networkSystem;
    };
}

#endif /* !SYSTEMMANAGER_HPP_ */
