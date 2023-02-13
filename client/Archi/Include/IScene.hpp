/*
** EPITECH PROJECT, 2023
** client
** File description:
** Iscene
*/

#ifndef ISCENE_HPP_
#define ISCENE_HPP_

#include <SFML/Graphics.hpp>
#include <vector>
#include "Entity.hpp"

namespace rtype{
    enum SceneType{
        NONE,
        MAIN_MENU,
        HELP,
        ENDGAME,
        DEATH,
        PAUSE
    }
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
}

#endif /* !ISCENE_HPP_ */