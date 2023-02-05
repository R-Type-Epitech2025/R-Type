#include "MovementManager.hpp"


namespace rtype{

    MouvementManager::MouvementManager(){
    }

    bool MouvementManager::LinkKeybordPosition(sf::Event &event, std::shared_ptr<rtype::Entity> entity){
        if (event.type == sf::Event::KeyPressed){
                std::cout << "pressed" << std::endl;
                if (event.key.code == sf::Keyboard::Down)
                    entity->setPosition(entity->x, entity->y + 10);
                else if (event.key.code == sf::Keyboard::Up)
                    entity->setPosition(entity->x, entity->y - 10);
                else if (event.key.code == sf::Keyboard::Left)
                    entity->setPosition(entity->x - 1, entity->y);
                else if (event.key.code == sf::Keyboard::Right)
                    entity->setPosition(entity->x + 1, entity->y);
        }
        return true;
    }
}