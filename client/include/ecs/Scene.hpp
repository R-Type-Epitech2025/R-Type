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

    class Scene : public QObject {

        Q_OBJECT
        
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
            void removeEntity(Entity *entity);

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
             ** @brief create an entity
             ** 
             ** @param entityCreator 
             */
            void createEntity(EntityCreator_t *entityCreator);
            
            /**
             * @brief 
             * 
             * @param entity 
             * @param entitiesCreator 
             */
            void updateEntity(Entity *entity, EntityCreator_t * entitiesCreator);

            /**
             * @brief udpate the texture of the entity
             * 
             * @param spriteName 
             */
            void updateTexture(std::string spriteName);
            
            /**
             * @brief remove an entity
             * 
             * @param entitiesCreator 
             * @param index 
             */
            void removeEntityCreator(std::vector<EntityCreator_t *> &entitiesCreator, int index);



            std::map<std::string, sf::Texture> textures;

        public slots:
            /**
             ** @brief slot activated when the entities need to be updated
             ** 
             ** @param entities 
             */
            void onUpdateEntities(std::vector<EntityCreator_t *> entities);

        protected:
        private:
            std::vector<Entity*> _entities;
            std::string _sceneName;
    };

    /**
     * @brief remove an entity
     * 
     * @param entitiesCreator 
     * @param index 
     */
    void removeEntityCreator(std::vector<EntityCreator_t *> &entitiesCreator, int index);
};

#endif /* !SCENE_HPP_ */

