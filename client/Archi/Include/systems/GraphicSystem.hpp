/*
** EPITECH PROJECT, 2023
** client
** File description:
** GraphicSystem
*/

#ifndef GRAPHICSYSTEM_HPP_
#define GRAPHICSYSTEM_HPP_
#include "../components/GraphicComponent.hpp"
#include "../SceneManager.hpp"
#include <SFML/Graphics.hpp>
#include "../Entity.hpp"

namespace rtype{
    class GraphicSystem {
        public:
            GraphicSystem();
            ~GraphicSystem();
            void init(SceneManager&);
            void Update(SceneManager&, int deltaTime);
            void destroy(SceneManager&);
            void loadEntity();
            void unloadEntity();
            void update(std::vector<Entity *>& entities);
        protected:
        private:
            GraphicComponent _graph;
    };
}

#endif /* !GRAPHICSYSTEM_HPP_ */
