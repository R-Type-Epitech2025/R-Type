#include "../../../include/ecs/components/MovementManager.hpp"
#include "../../../include/ecs/Entity.hpp"

//structure pour faire bouger les sprites
    // position
    // 

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


    bool MouvementManager::SetNewPosition(Mouvement_Keyboard mouv){
    }
    


    bool MouvementManager::LinkKeybordPosition(sf::Event &event, std::shared_ptr<rtype::Entity> entity){
        if (event.type == sf::Event::KeyPressed){
                    if (event.key.code == sf::Keyboard::Down){
                        entity->setPosition(entity->x, entity->y + 10);
                        //entity->new_data(DIRECTION::UP);
                    }else if (event.key.code == sf::Keyboard::Up){
                        entity->setPosition(entity->x, entity->y - 10);
                        //entity->new_data(DIRECTION::DOWN);
                    } else if (event.key.code == sf::Keyboard::Left){
                        entity->setPosition(entity->x - 10, entity->y);
                        //entity->new_data(DIRECTION::LEFT);
                    }else if (event.key.code == sf::Keyboard::Right){
                        entity->setPosition(entity->x + 10, entity->y);
                        //entity->new_data(DIRECTION::RIGHT);
            }
            return true;
        }
    }

}

