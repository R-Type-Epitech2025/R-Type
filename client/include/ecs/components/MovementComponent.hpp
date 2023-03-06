/*
** EPITECH PROJECT, 2023
** Archi
** File description:
** MovementComponent
*/

#ifndef MOVEMENTCOMPONENT_HPP_
#define MOVEMENTCOMPONENT_HPP_

#include "EntityCreator.hpp"


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
            MovementComponent(std::vector<int> positioninscreen, bool keyboardLink, std::vector<int> setVelocity = {0, 0});

            /**
             ** @brief Destroy the Movement Component object
             ** 
             */
            ~MovementComponent();

            /**
             ** @brief Set the position strutc
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
             ** @brief Set the velocity strutc
             ** 
             ** @param velocityX
             ** @param velocityY
             **/
            void applyVelocity();

            /**
             * @brief Check if the entity is out of the screen and set it back to the other side
             * 
             */
            void checkParallax();
            
            /**
             ** @brief Update the movement component
             ** 
             ** @param entity 
             */
            void update(EntityCreator_t *entity);

        void LinktoKeybord(bool link);
        bool is_linked() const;
        bool isParallax;
        protected:
        private:
            bool _link;
    };
}

#endif /* !MOVEMENTCOMPONENT_HPP_ */
