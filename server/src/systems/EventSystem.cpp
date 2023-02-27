/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** EventSystem
*/

#include "../../include/systems/EventSystem.hpp"
#include <iostream>
#include "../../include/ecs/Entity.hpp"

namespace rtype{
    namespace system {
        /**
         * @brief Construct a new Event System::Event System object
         * 
         * @param window 
         */
        EventSystem::EventSystem(sf::RenderWindow &window ) : _window( window) , _movement()
        {
        }

        /**
         * @brief Destroy the Event System::Event System object
         * 
         */
        EventSystem::~EventSystem()
        {
        }

        /**
         * @brief Handle the event of the window
         * 
         * @param entities 
         */
        void EventSystem::update(std::vector<std::shared_ptr<Entity> > &entities)
        {
            sf::Event event;
            while (_window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    _window.close();
                else if (event.type == sf::Event::MouseButtonPressed)
                { 
                
                    entities.push_back(std::shared_ptr<Entity>(new Entity()));
                    auto& newEntity = entities.back();
                    newEntity->x = event.mouseButton.x;
                    newEntity->y = event.mouseButton.y;
                    if (entities.size() == 1){
                        newEntity->Player = true;
                        newEntity->color = "Red";
                    }else{
                        newEntity->Player = false;
                        newEntity->color = "blue";
                    }
                    std::cout<<"New entity"<<std::endl;
                }
                for (int i = 0; i < entities.size(); i++){
                    if (entities.at(i)->Player){   
                        _movement.LinkKeybordPosition(event, entities.at(i));
                    }
                }
            }
        }
    }
}