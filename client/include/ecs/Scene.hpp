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
            Scene(std::string sceneName);

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

        // /**
        //  ** @brief Get the Entities object
        //  ** 
        //  ** @return std::vector<IEntity> 
        //  */
        // std::vector<IScene> entityList();

            /**
             ** @brief Update the Scene object
             ** 
             ** @param entity 
             ** @param window 
             */
            void update(Entity& entity, sf::RenderWindow& window);

        // void draw(sf::RenderWindow& window) final; // Draw the scene


            /**
             ** @brief Add an entity to the scene
             ** 
             ** @param entity 
             */
            void addEntity(Entity* entity);
        
            /**
             ** @brief get an entity from vector
             ** 
             ** @param entity 
             */
            std::vector<Entity*> get_entities();

            /**
             ** @brief remove an entity from the scene
             ** 
             ** @param entity 
             */
            void removeEntity(rtype::Entity *entity);

            /**
             ** @brief get an entity from the scene
             ** 
             ** @param entity 
             */
            Entity *getEntity(quint32 id);

            /**
             ** @brief Get the Scene Name object
             ** 
             ** @return std::string 
             */
            std::string getSceneName() const;

            /**
             ** @brief Update all the entities in the scene
             **
             ** @param std::vector <Entity*> entities
             */
            void onUpdateEntities(std::vector <Entity*> entities);

        protected:
        private:
            std::vector<Entity*> _entities;
            std::string _sceneName;
    };
};

#endif /* !SCENE_HPP_ */

