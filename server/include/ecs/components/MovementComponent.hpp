/*
** EPITECH PROJECT, 2023
** Archi
** File description:
** MovementComponent
*/

#ifndef MOVEMENTCOMPONENT_HPP_
#define MOVEMENTCOMPONENT_HPP_

#include <memory>
#include <iostream>
#include <vector>

namespace rtype{

    /**
     ** @brief Enum for the direction of the movement
     ** 
     */
    enum DIRECTION{
            RIGHT,
            LEFT,
            UP,
            DOWN
        };
    class MovementComponent {
        public:
            /**
             ** @brief Construct a new Movement Component object
             ** 
             ** @param positioninscreen 
             ** @param keyboardLink 
             ** @param setVelocity 
             */
            MovementComponent(std::vector<int> positioninscreen, bool keyboardLink, std::vector<int> setVelocity);

            /**
             ** @brief Destroy the Movement Component object
             ** 
             */
            ~MovementComponent();

            /**
             ** @brief set the position of the entity
             ** 
             */
            struct position {
                int x;
                int y;
            };

            typedef struct position position;
            position pos;
            float rotation;
            position velocity;
        
        /**
         ** @brief link to the keyboard 
         ** 
         ** @param link 
         */
        void LinktoKeybord(bool link);

        /**
         ** @brief check if the entity is linked
         ** 
         ** @return true 
         ** @return false 
         */
        bool is_linked() const;
        protected:
        private:
            bool _link;
    };
}

#endif /* !MOVEMENTCOMPONENT_HPP_ */
