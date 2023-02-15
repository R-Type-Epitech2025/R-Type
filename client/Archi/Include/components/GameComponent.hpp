/*
** EPITECH PROJECT, 2023
** Archi
** File description:
** GameComponent
*/

#ifndef GAMECOMPONENT_HPP_
#define GAMECOMPONENT_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


namespace rtype{
    class GameComponent {
        public:
            enum class Type {
                TURRET,
                SHIP,
                MONSTER,
                BOSS
            };

            GameComponent();
            ~GameComponent();
            int _health;
            bool _alive;
            bool _attack;
            struct position{
                int x;
                int y;
            };
            typedef struct position position;
            protected:
        private:
    };
}

#endif /* !GAMECOMPONENT_HPP_ */
