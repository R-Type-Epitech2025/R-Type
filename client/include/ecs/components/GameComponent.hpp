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

            struct position{
                int x;
                int y;
            };

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
            
            
            typedef struct position position;
            protected:
        private:
            bool _attack;
            int _health;
            bool _alive;

    };
}

#endif /* !GAMECOMPONENT_HPP_ */
