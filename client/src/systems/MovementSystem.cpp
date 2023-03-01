/*
** EPITECH PROJECT, 2023
** client
** File description:
** MovementSystem
*/

#include "systems/MovementSystem.hpp"
#include <iostream>

namespace rtype{
    namespace system {

        MovementSystem::MovementSystem() /*: QObject(nullptr)*/ {
        }

        MovementSystem::~MovementSystem(){
        }
        
        void MovementSystem::update(rtype::SceneManager *Manager, sf::Event event){

            Scene *Scene = Manager->getCurrentScene();

            for (Entity *entity : Scene->get_entity()){
                if (entity->container.movement_component->is_linked() == true){
                    if (event.type == sf::Event::KeyPressed){   
                        if (event.key.code == sf::Keyboard::Up) {
                            // entity->set_direction(rtype::DIRECTION::TOP);
                            entity->container.movement_component->pos.y -= 5;
                        } else if (event.key.code == sf::Keyboard::Down){
                            // entity->set_direction(rtype::DIRECTION::BOTTOM);
                            entity->container.movement_component->pos.y += 5;
                        } else if (event.key.code == sf::Keyboard::Left){
                            // entity->set_direction(rtype::DIRECTION::FORWARD);
                            entity->container.movement_component->pos.x -= 5;
                        }
                        else if (event.key.code == sf::Keyboard::Right){
                            // entity->set_direction(rtype::DIRECTION::BACKWARD);
                            entity->container.movement_component->pos.x += 5;
                        }

                    }       
                }   
            }
        }
    }
}

