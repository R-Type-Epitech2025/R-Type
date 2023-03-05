/*
** EPITECH PROJECT, 2023
** client
** File description:
** GraphicSystem
*/

#ifndef GRAPHICSYSTEM_HPP_
#define GRAPHICSYSTEM_HPP_

#include "ISystem.hpp"

namespace rtype{

    class GraphicSystem : public QObject {

        Q_OBJECT

        public:
            /**
             ** @brief Construct a new Graphic System object
             ** 
             ** @param parent 
             */
            GraphicSystem(QObject *parent = nullptr);

            /**
             ** @brief Destroy the Graphic System object
             ** 
             */
            ~GraphicSystem();

            /**
             ** @brief Get the Type object
             ** 
             ** @return SystemType 
             */
            SystemType getType() const { return SystemType::GRAPHIC; };

            /**
             ** @brief init the graphic system
             ** 
             ** @param SceneManager 
             ** @param sf::RenderWindow 
             */
            void init(SceneManager&, sf::RenderWindow &);

            /**
             ** @brief update the graphic system
             ** 
             ** @param SceneManager 
             ** @param deltaTime 
             */
            void update(SceneManager* manager, uint64_t time);
        protected:
        private:

        public slots:
            /**
             ** @brief slot activated when the entities need to be updated
             ** 
             ** @param entities 
             */
            void onUpdateEntities(std::vector<Entity *> entities);
        
        signals:
            /**
             ** @brief signal emitted when the entities need to be updated
             ** 
             ** @param entities 
             */
            void updateEntities(std::vector<Entity *> entities);
    };
}

#endif /* !GRAPHICSYSTEM_HPP_ */
