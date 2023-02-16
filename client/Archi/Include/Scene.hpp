/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Scene
*/

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <vector>
#include <SFML/Graphics.hpp>
#include "IScene.hpp"

namespace rtype {
class Scene : public rtype::IScene{
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
        // std::vector getScene(std::vector<IEntity> entities); // Get the scene

        // /**
        //  * @brief Get the Entities object
        //  * 
        //  * @return std::vector<IEntity> 
        //  */
        // std::vector<IScene> entityList();

        void update(Entity& entity, sf::RenderWindow& window); // Update the scene

        void draw(sf::RenderWindow& window) final; // Draw the scene

        void getScene(std::vector<IScene> scene) final;

    protected:
    private:
};
};

#endif /* !SCENE_HPP_ */

