/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** MovementSystem
*/

#ifndef MOVEMENTSYSTEM_HPP_
#define MOVEMENTSYSTEM_HPP_

namespace rtype {
    class MovementSystem {
        public:
            enum _Direction
                {   Down,
                    Left,
                    Right,
                    Up };
            MovementSystem();
            MovementSystem(const sf::Texture&);
            ~MovementSystem();
            void moveUp(sf::Vector2i& , sf::Sprite&, float);
            void moveLeft(sf::Vector2i& , sf::Sprite&, float);
            void moveRight(sf::Vector2i& , sf::Sprite&, float);
            void moveDown(sf::Vector2i& , sf::Sprite&, float);
        protected:
        private:
    };
}

#endif /* !MOVEMENTSYSTEM_HPP_ */
