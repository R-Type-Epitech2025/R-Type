
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "../Entity.hpp"

namespace rtype {
    class MouvementManager {
    public:

    /**
     * @brief enum of the mouvement
     * 
     */
    enum Mouvement {
            Up = sf::Keyboard::Up ,
            Down = sf::Keyboard::Down,
            Left = sf::Keyboard::Left,
            Right = sf::Keyboard::Right
        };

        /**
         * @brief Construct a new Mouvement Manager object
         * 
         */
        MouvementManager();

        /**
         * @brief set the new position of the entity
         * 
         */
        bool SetNewPosition(Mouvement mouv);

        /**
         * @brief link the keyboard to the entity
         * 
         * @param event 
         * @param entity 
         * @return true 
         * @return false 
         */
        bool LinkKeybordPosition(sf::Event &event, std::shared_ptr<rtype::Entity> entity);
    private :

    };
}