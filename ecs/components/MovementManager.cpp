#include "MovementManager.hpp"


namespace rtype{

    /**
     * @brief Construct a new Mouvement Manager:: Mouvement Manager object
     * 
     */
    MouvementManager::MouvementManager(){
    }

    /**
     * @brief mouvement of the entity
     * 
     * @param event 
     * @param entity 
     * @return true 
     * @return false 
     */
    bool MouvementManager::LinkKeybordPosition(sf::Event &event, std::shared_ptr<rtype::Entity> entity){
        if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Down)
                    entity->setPosition(entity->x, entity->y + 10);
                else if (event.key.code == sf::Keyboard::Up)
                    entity->setPosition(entity->x, entity->y - 10);
                else if (event.key.code == sf::Keyboard::Left)
                    entity->setPosition(entity->x - 10, entity->y);
                else if (event.key.code == sf::Keyboard::Right)
                    entity->setPosition(entity->x + 10, entity->y);
        }
        return true;
    }
}