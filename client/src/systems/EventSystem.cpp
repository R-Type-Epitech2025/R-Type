/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** EventSystem
*/

#include "./systems/EventSystem.hpp"
#include <iostream>
#include "./ecs/Entity.hpp"

namespace rtype{
    namespace system {
        EventSystem::EventSystem(sf::RenderWindow &window ) : _window( window) , _mouvement()
        {
        }
        EventSystem::~EventSystem()
        {
        }
//         void EventSystem::update(std::vector<std::shared_ptr<Entity> > &entities)
//         {
//             sf::Event event;
//             while (_window.pollEvent(event))
//             {
//                 if (event.type == sf::Event::Closed)
//                     _window.close();
//                 else if (event.type == sf::Event::MouseButtonPressed)
//                 { 
                
//                     entities.push_back(std::shared_ptr<Entity>(new Entity()));
//                     auto& newEntity = entities.back();
//                     newEntity->x = event.mouseButton.x;
//                     newEntity->y = event.mouseButton.y;
//                     if (entities.size() == 1){
//                         newEntity->Player = true;
//                         newEntity->color = "Red";
//                     }else{
//                         newEntity->Player = false;
//                         newEntity->color = "blue";
//                     }
//                     std::cout<<"New entity"<<std::endl;
//                 }
//                 for (int i = 0; i < entities.size(); i++){
//                     if (entities.at(i)->Player){   
//                         _mouvement.LinkKeybordPosition(event, entities.at(i));
//                     }
//                 }
//             }
//         }
    }
}