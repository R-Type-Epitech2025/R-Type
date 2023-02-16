/*
** EPITECH PROJECT, 2023
** client
** File description:
** Component
*/

#ifndef IEntity_HPP_
#define IEntity_HPP_

#include <iostream>
#include <vector>

namespace rtype {
class IEntity {
    public:
        /**
         * @brief Destroy the IEntity object
         * 
         */
        virtual ~IEntity() = 0;

        /**
         * @brief 
         * 
         * @return std::vector<Entity> 
         */
        void ComponentList(); // Get the components of the entity

    protected:
    private:
};
};

#endif /* !IENTITY_HPP_ */
