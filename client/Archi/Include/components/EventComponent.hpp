/*
** EPITECH PROJECT, 2023
** Archi
** File description:
** EventComponent
*/

#ifndef EVENTCOMPONENT_HPP_
#define EVENTCOMPONENT_HPP_

class EventComponent {
    public:
        EventComponent();
        ~EventComponent();
        struct hitbox{
            int x;
            int y;
            int width;
            int height;
        };
        bool ishooting;
        typedef struct hitbox hitbox;
    protected:
    private:
};

#endif /* !EVENTCOMPONENT_HPP_ */
