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
        
        bool isAlive() const;
        bool isDead() const;

        void setAlive(bool alive);
        void setDead(bool dead);

        void takeDamage(int damage);
        Type getType() const;
        void setHealth(int health);
        int getHealth() const;

        void setDrop();
        bool isAttacking();
        void setSpeed(int speed);
        void getSpeed() const;

        sf::Sound setSound();
        void getSound() const;

        protected:
    private:
        int _health;
        int _speed;
        bool _alive;
        bool _dead;
        bool _drop;
        bool _attack;
        Type _type;
};

#endif /* !GAMECOMPONENT_HPP_ */
