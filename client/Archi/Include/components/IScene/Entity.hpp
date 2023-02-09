/*
** EPITECH PROJECT, 2023
** client
** File description:
** Component
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

class Entity {
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

        void createEntity();

        void EntityPath(); // Path in the map

        int idCreator(); // id of the entity

    protected:
    private:
};

#endif /* !COMPONENT_HPP_ */
