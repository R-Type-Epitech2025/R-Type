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
    enum DIRECTION{
            RIGHT,
            LEFT,
            UP,
            DOWN
        };
    class MovementComponent {
        public:
            MovementComponent(std::vector<int> positioninscreen, bool keyboardLink);
            ~MovementComponent();
            struct position {
                int x;
                int y;
            };
            typedef struct position position;
            position pos;
            float rotation;
            float velocity;
        void LinktoKeybord(bool link);
        bool is_linked() const;
        protected:
        private:
            bool _link;
    };
}

#endif /* !MOVEMENTCOMPONENT_HPP_ */
