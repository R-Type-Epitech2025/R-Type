/*
** EPITECH PROJECT, 2023
** client
** File description:
** Component
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include "IEntity.hpp"
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>


namespace rtype {
    class Entity : public rtype::IEntity {
    public:
        /**
         * @brief Construct a new Entity object
         * 
         */
        Entity();

        /**
         * @brief Destroy the Entity object
         * 
         */
        ~Entity();

        /**
         * @brief Create a Entity object
         * 
         * @return std::vector<Entity> 
         */
        std::vector<Entity> createEntity();

        /**
         * @brief 
         * 
         * @param XY 
         * @param entityID 
         */
        void EntityPath(std::vector<int> XY, int entityID); // Path in the map

        /**
         * @brief 
         * 
         * @param entity 
         * @return int 
         */
        std::vector<Entity> idCreator(std::vector<Entity> entity); // id of the entity

        // Load the entity
        sf::Vector2f position;
        sf::Texture texture;


    protected:
    private:
};
};

#endif /* !ENTITY_HPP_ */
