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
            GraphicSystem(QObject *parent = nullptr);
            ~GraphicSystem() {};
            SystemType getType() const { return SystemType::GRAPHIC; };
            void init(SceneManager&, sf::RenderWindow &);
            void update(rtype::SceneManager* Manager, uint64_t time);
        protected:
        private:
        public slots:
            void onUpdateSprites(std::vector<Entity *> entities);
    };
}

#endif /* !GRAPHICSYSTEM_HPP_ */
