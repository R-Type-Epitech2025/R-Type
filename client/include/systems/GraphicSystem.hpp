/*
** EPITECH PROJECT, 2023
** client
** File description:
** GraphicSystem
*/

#ifndef GRAPHICSYSTEM_HPP_
#define GRAPHICSYSTEM_HPP_
#include "ecs/components/GraphicComponent.hpp"
#include "ecs/SceneManager.hpp"
#include <SFML/Graphics.hpp>
#include "ecs/Entity.hpp"
#include <iostream>

namespace rtype{
    class GraphicSystem: public QObject, public ISystem {
        public:
            GraphicSystem();
            ~GraphicSystem();
            void init(SceneManager&);
            void Update(SceneManager* Manager, int deltaTime, sf::RenderWindow &window);
            void destroy(SceneManager&);
            void loadEntity();
            void unloadEntity();
            void update(std::vector<Entity *>& entities);
        protected:
        private:
            GraphicComponent _graph;

        public slots:
            void onUpdateSprites(std::list<Sprite *> sprites);
    };
}

#endif /* !GRAPHICSYSTEM_HPP_ */
