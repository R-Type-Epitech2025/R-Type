/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** EventSystem
*/

#ifndef EVENTSYSTEM_HPP_
#define EVENTSYSTEM_HPP_

#include <SFML/Graphics.hpp>
#include "../Entity.hpp"
#include <memory>
#include "../components/MovementManager.hpp"

namespace rtype {
    class EventSystem {
        public:

            /**
             * @brief Construct a new Event System object
             * 
             * @param window 
             */
            EventSystem(sf::RenderWindow& window);

            /**
             * @brief Destroy the Event System object
             * 
             */
            ~EventSystem();

            /**
             * @brief Update the event of the window
             * 
             * @param entities 
             */
            void update(std::vector<std::shared_ptr<rtype::Entity> >& entities);

        protected:
        private:
            sf::RenderWindow& _window;
            rtype::MouvementManager  _mouvement;

};
}

#endif /* !EVENTSYSTEM_HPP_ */
