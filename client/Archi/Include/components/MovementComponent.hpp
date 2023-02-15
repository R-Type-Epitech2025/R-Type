/*
** EPITECH PROJECT, 2023
** Archi
** File description:
** MovementComponent
*/

#ifndef MOVEMENTCOMPONENT_HPP_
#define MOVEMENTCOMPONENT_HPP_
#include <iostream> //inclure plus bas par la suite !!



namespace rtype{
    class MovementComponent {
        public:
            MovementComponent();
            ~MovementComponent();
            struct position {
                int x;
                int y;
            };
            typedef struct position position;
            float rotation;
            float velocity;
        protected:
        private:
    };
}

#endif /* !MOVEMENTCOMPONENT_HPP_ */
