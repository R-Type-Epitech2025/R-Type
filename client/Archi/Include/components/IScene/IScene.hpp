/*
** EPITECH PROJECT, 2023
** client
** File description:
** Iscene
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include <SFML/Graphics.hpp>
#include <vector>

class IScene {
    public:
        
        /**
         * @brief Construct a new IScene object
         * 
         */
        IScene();

        /**
         * @brief Destroy the IScene object
         * 
         */
        ~IScene();

        /**
         * @brief 
         * 
         * @param window 
         */
        void draw(sf::RenderWindow &window);

        /**
         * @brief Get the Scene object
         * 
         * @param scene 
         */
        void getScene(std::vector<IScene> scene);

    protected:
    private:
};

#endif /* !COMPONENT_HPP_ */