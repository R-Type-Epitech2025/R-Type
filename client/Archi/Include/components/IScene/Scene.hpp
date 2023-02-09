/*
** EPITECH PROJECT, 2023
** client
** File description:
** Component
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include "IEntity.hpp"
#include <iostream>
#include <vector>


class Scene {
    public:
        /**
         * @brief Construct a new Scene object
         * 
         */
        Scene();

        /**
         * @brief Destroy the Scene object
         * 
         */
        ~Scene();

        /**
         * @brief Get the Scene object
         * 
         * @param entities 
         * @return std::vector 
         */
        std::vector getScene(std::vector<IEntity> entities); // Get the scene


    protected:
    private:
};

#endif /* !COMPONENT_HPP_ */
