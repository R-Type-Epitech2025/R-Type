/*
** EPITECH PROJECT, 2023
** Archi
** File description:
** GameComponent
*/

#ifndef GAMECOMPONENT_HPP_
#define GAMECOMPONENT_HPP_
#include <SFML/Graphics.hpp>

namespace rtype{
    class GameComponent {
        public:
            GameComponent();
            ~GameComponent();
            void setAttack(bool attack);
            void setHealth(int health);

            bool IsAlive(bool alive);
            bool isAttack(bool attack);

            void setAlive(bool alive);
            void setDead(bool alive);
            void setPos(int x, int y);
            void setSound(const std::string &soundPath);
            void getSound();
            
        protected:
        private:
            bool _attack;
            int _health;
            bool _alive;

    };
}

#endif /* !GAMECOMPONENT_HPP_ */
