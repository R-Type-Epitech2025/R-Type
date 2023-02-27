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
    namespace system {

        class GraphicSystem: public QObject {

            Q_OBJECT

            public:
                GraphicSystem();
                ~GraphicSystem();
                void init(SceneManager&) {};
                void Update(rtype::SceneManager* Manager, int deltaTime, sf::RenderWindow &window);
                void destroy(SceneManager&) {};
                void loadEntity() {};
                void unloadEntity() {};
            protected:
            private:
                GraphicComponent _graph;

            public slots:
                void onUpdateSprites(std::list<sf::Sprite *> sprites);
        };
    }
}

#endif /* !GRAPHICSYSTEM_HPP_ */
