/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Entity
*/
#ifndef ENTITY_HPP_
#define ENTITY_HPP_
namespace rtype {
    class Entity
    {
    private:
        /* data */
    public:
        int x;
        int y;
        bool Player;
        Entity();
        void setPosition(int x, int y);
    };
    
}
#endif /* !ENTITY_HPP_ */