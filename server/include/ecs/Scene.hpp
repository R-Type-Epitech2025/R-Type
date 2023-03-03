/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Scene
*/

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include "Entity.hpp"

namespace rtype {
class Scene{
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

        void update(Entity& entity, sf::RenderWindow& window);

        // void draw(sf::RenderWindow& window) final; // Draw the scene
        void addEntity(Entity* entity);
        
        std::vector<Entity*> get_entities();
        Entity *getEntity(std::string id);
    protected:
    private:
        std::vector<Entity*> _entities;
    
};
};

#endif /* !SCENE_HPP_ */

