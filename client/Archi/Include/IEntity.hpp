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
         * @brief Construct a new IEntity object
         * 
         */
        IEntity();

        /**
         * @brief Destroy the IEntity object
         * 
         */
        ~IEntity();

        /**
         * @brief 
         * 
         * @param id 
         */
        void addComponent(int id); // push back in vector


    protected:
    private:
};
};

#endif /* !IENTITY_HPP_ */
