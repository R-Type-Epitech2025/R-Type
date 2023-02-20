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

namespace rtype {
    enum SceneType{
        NONE,
        MAIN_MENU,
        HELP,
        ENDGAME,
        DEATH,
        PAUSE
    };
    class IScene {
        public:

            /**
             * @brief 
             * 
             * @param window 
             */
            virtual void draw(sf::RenderWindow &window) = 0;

            /**
             * @brief Get the Scene object
             * 
             * @param scene 
             */
            virtual void getScene(std::vector<IScene> scene) = 0;

            // /**
            // * @brief 
            // * 
            // * @param id 
            // */
            // virtual void addEntity(int id) = 0; // push back in vector

            // /**
            // * @brief 
            // * 
            // * @param id 
            // */
            // virtual void removeEntity(int id) = 0; // remove in vector



        protected:
        private:
    };
};

#endif /* !ISCENE_HPP_ */