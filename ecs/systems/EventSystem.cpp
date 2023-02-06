/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** EventSystem
*/

#include "EventSystem.hpp"
#include <iostream>
#include "../Entity.hpp"

/**
 * @brief Construct a new rtype::Event System::Event System object
 * 
 * @param window 
 */
rtype::EventSystem::EventSystem(sf::RenderWindow &window ) : _window( window) , _mouvement()
{
}

/**
 * @brief Destroy the rtype::Event System::Event System object
 * 
 */
rtype::EventSystem::~EventSystem()
{
}

/**
 * @brief Handle the event of the window
 * 
 * @param entities 
 */
void rtype::EventSystem::update(std::vector<std::shared_ptr<rtype::Entity> > &entities)
{
    sf::Event event;
    while (_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            _window.close();
        else if (event.type == sf::Event::MouseButtonPressed)
        { 
         
            entities.push_back(std::shared_ptr<rtype::Entity>(new Entity()));
            auto& newEntity = entities.back();
            newEntity->x = event.mouseButton.x;
            newEntity->y = event.mouseButton.y;
            newEntity->Player = true;
            std::cout<<"New entity"<<std::endl;
        }
        for (int i = 0; i < entities.size(); i++){
            if (entities.at(i)->Player){   
                _mouvement.LinkKeybordPosition(event, entities.at(i));
            }
        }
    }
}