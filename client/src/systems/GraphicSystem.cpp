/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** graphicSystem
*/
#include "systems/GraphicSystem.hpp"
#include <iostream>
#include <string>

namespace rtype {
        /**
         * @brief Construct a new Graphic System::Graphic System object
         * 
         * @param window 
         */
        GraphicSystem::GraphicSystem()
        {
                    std::cout << "Hello World" << std::endl;
                

        }

        /**
         * @brief Destroy the Graphic System::Graphic System object
         * 
         */
        

        GraphicSystem::~GraphicSystem()
        {
        }

        /**
         * @brief Update the graphic of the window
         * 
         * @param entities 
         */
        void GraphicSystem::Update(SceneManager* Manager, int deltaTime, sf::RenderWindow &window)
        {
            Scene *scene = Manager->getCurrentScene();
            int i = 0;
            int save = 0;
            for (const Entity *entity : scene->get_entity())
            {
                // if (entity->container.graphic_component->counter_sprites == entity->container.graphic_component->nb_sprites){
                //     entity->container.graphic_component->setSpritePosition(entity->container.graphic_component->initial_sprite_x, entity->container.graphic_component->position.sprite_y);
                //     entity->container.graphic_component->counter_sprites = 0;
                // }
                // entity->container.graphic_component->counter_sprites += 1;
                entity->container.graphic_component->setPosition(entity->container.movement_component->pos.x, entity->container.movement_component->pos.y);
                save = entity->container.graphic_component->position.sprite_x;
                entity->container.graphic_component->setSpritePosition(entity->container.graphic_component->position.sprite_x, entity->container.graphic_component->position.sprite_y);
                window.draw(entity->container.graphic_component->getSprite());
            }   
            window.display();
            window.clear();
        }

        void GraphicSystem::onUpdateSprites(std::list<Sprite *> sprites)
        {
            return;
        }

} // namespace rType