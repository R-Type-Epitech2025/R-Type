/*
** EPITECH PROJECT, 2023
** client
** File description:
** Animation
*/

#ifndef ANIMATION_HPP_
#define ANIMATION_HPP_

#include <SFML/Graphics.hpp>

class Animation {
    public:
        enum class AnimationType {
            NONE = -1,
            IDLE,
            SHOOT,
            TRACK,
            DOWN,
            DEATH,
            UP,
            LEFT,
            RIGHT,
            HIT
        };
        Animation();
        ~Animation();

        void setAnimationType(AnimationType type);
        void setY(int y);
        void setX(int x);
        void setAnimation(bool action);
        AnimationType getType();
        int getY();
        int getX();
        bool getAnimation();
        void setframenb(int nb);
        int getframenb();

        void clockReset();
        void setframe(sf::Time currentFrame);
        sf::Time getframe();
        sf::Clock getClock();
        int getPosX();
        int getPosY();
        void setPosX(int posX);
        void setPosY(int posX);



    protected:
    private:
        AnimationType _animation;
        int _y;
        int _x;
        bool _actions;
        int _nb;
        sf::Clock _clock;
        sf::Time _currentFrame;
        int _posX;
        int _posY;
};

#endif /* !ANIMATION_HPP_ */
