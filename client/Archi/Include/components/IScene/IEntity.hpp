/*
** EPITECH PROJECT, 2023
** client
** File description:
** Component
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

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

        void addComponent(int id); // push back in vector


    protected:
    private:
};

#endif /* !COMPONENT_HPP_ */
