/*
** EPITECH PROJECT, 2023
** client
** File description:
** MovementSystem
*/

#include "../Include/systems/MovementSystem.hpp"
#include <iostream>

namespace rtype{

    MouvementSystem::MouvementSystem(){
    }

    MouvementSystem::~MouvementSystem(){
    }
    
    void MouvementSystem::update(SceneManager *Manager, sf::Event event){

        Scene *Scene = Manager->getCurrentScene();

        for (Entity *entity : Scene->get_entity()){
            if (entity->container.movement_component->is_linked()){
                if (event.type == sf::Event::KeyPressed){   
                    if (event.key.code == sf::Keyboard::Up) {
                        entity->set_direction(rtype::DIRECTION::TOP);
                        entity->container.movement_component->pos.y -= 5;
                    } else if (event.key.code == sf::Keyboard::Down){
                        entity->set_direction(rtype::DIRECTION::BOTTOM);
                        entity->container.movement_component->pos.y += 5;
                    }
                }       
            }   
        }
    }
    
    

}

