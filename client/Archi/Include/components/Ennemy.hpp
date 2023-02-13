/*
** EPITECH PROJECT, 2023
** Archi
** File description:
** Ennemy
*/

#ifndef ENNEMY_HPP_
#define ENNEMY_HPP_

#include <SFML/Graphics.hpp>
#include "Hitbox.hpp"
#include "Animation.hpp"
#include "Velocity.hpp"
#include "Position.hpp"
#include "Component.hpp"

class Ennemy {
    public:
        enum class Type {
            TURRET,
            SHIP,
            MONSTER,
            BOSS
        };
        Ennemy();
        ~Ennemy();

        bool isAlive() const;
        bool isDead() const;

        void setAlive(bool alive);
        void setDead(bool dead);

        void takeDamage(int damage);
        Type getType() const;
        void setHealth(int health);
        int getHealth() const;

        void setDrop();


    protected:
    private:
};

#endif /* !ENNEMY_HPP_ */
