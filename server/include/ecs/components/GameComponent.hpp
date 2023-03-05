/*
** EPITECH PROJECT, 2023
** Archi
** File description:
** GameComponent
*/

#ifndef GAMECOMPONENT_HPP_
#define GAMECOMPONENT_HPP_

#include <SFML/Graphics.hpp>
#include <QtNetwork>

#include <memory>
#include <iostream>

namespace rtype{
    class GameComponent {
        public:

            /**
             ** @brief Construct a new Game Component object
             ** 
             */
            GameComponent(int cooldown = 0, int last_shot = 0, int health = 1, int damage = 1);

            /**
             ** @brief Destroy the Game Component object
             ** 
             */
            ~GameComponent();
            int cooldown;
            int last_shot;
            int health;
            int damage;
        protected:
        private:
    };
}

#endif /* !GAMECOMPONENT_HPP_ */
