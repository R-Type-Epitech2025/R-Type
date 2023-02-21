/*
** EPITECH PROJECT, 2023
** Archi
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Sprite.hpp"
#include "Hitbox.hpp"
#include "Velocity.hpp"
#include "Animation.hpp"


class Player {
    public:
        Player();
        ~Player();

        void setPosition(sf::Vector2f pos);

        bool isAlive() const;
        bool isDead() const;
        bool isAttacking() const;

        void setAlive(bool alive);
        void setDead(bool dead);

        void setAttack();
        void setMove();

        void setSpeed(int speed);
        int getSpeed() const;

        void setAnim(Animation::AnimationType anim);
        Animation::AnimationType getAnim();

    protected:
    private:
        int8_t id;
        Animation::AnimationType _animation;
        Position _pos;
        bool _alive;
        bool _dead;
        bool _attack;
        bool _move;
        int _speed;
};

#endif /* !PLAYER_HPP_ */
