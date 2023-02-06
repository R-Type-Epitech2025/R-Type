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
    /**
     * @brief Construct a new Entity:: Entity object
     * 
     */
    Entity::Entity(){
        std::cout << "hey " << std::endl;
    }   

    /**
     * @brief Set the Position object
     * 
     * @param x 
     * @param y 
     */
    void Entity::setPosition(int x , int y){
        this->x = x;
        this->y = y;
        std::cout <<"changed position " << std::endl;
    }



    

} // namespace rtype
