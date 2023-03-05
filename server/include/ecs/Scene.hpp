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
         ** @brief Construct a new Scene object
         ** 
         */
        Scene();

        /**
         ** @brief Destroy the Scene object
         ** 
         */
        ~Scene();

        /**
         ** @brief Get the Scene object
         ** 
         ** @param entities 
         ** @return std::vector 
         */
        // std::vector getScene(std::vector<IEntity> entities); // Get the scene

        /**
         ** @brief Add the Entity object
         ** 
         ** @param entity 
         */
        void addEntity(Entity* entity);
        
        /**
         ** @brief Get the Entities object
         ** 
         ** @return std::vector<Entity*> 
         */
        std::vector<Entity*> getEntities();

        /**
         ** @brief Get the Entity object
         ** 
         ** @param id 
         ** @return Entity* 
         */
        Entity *getEntity(quint32 id);
    protected:
    private:
        std::vector<Entity*> _entities;
    
};
};

#endif /* !SCENE_HPP_ */

