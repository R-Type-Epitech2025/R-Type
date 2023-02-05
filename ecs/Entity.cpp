/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Entity
*/
#include "Entity.hpp"
#include <iostream>
namespace rtype
{
    Entity::Entity(){
        std::cout << "hey " << std::endl;
    }   

    void Entity::setPosition(int x , int y){
        this->x = x;
        this->y = y;
        std::cout <<"changed position " << std::endl;
    }



    

} // namespace rtype
