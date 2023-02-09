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

        /**
         * @brief Create a Entity object
         * 
         */
        void createEntity();

        /**
         * @brief Destroy the Entity object
         * 
         */
        void EntityPath(); // Path in the map

        /**
         * @brief Get the Id Creator object
         * 
         * @return int 
         */
        int idCreator(); // id of the entity

    protected:
    private:
};

#endif /* !COMPONENT_HPP_ */
