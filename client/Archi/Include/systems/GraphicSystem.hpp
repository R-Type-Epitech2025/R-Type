/*
** EPITECH PROJECT, 2023
** client
** File description:
** GraphicSystem
*/

#ifndef GRAPHICSYSTEM_HPP_
#define GRAPHICSYSTEM_HPP_
#include "ISystem.hpp"
#include "GraphicComponent.hpp"

namespace rtype{
    class GraphicSystem : public ISystem {
        public:
            GraphicSystem();
            ~GraphicSystem();
            void init(SceneManager&) override;
            void Update(SceneManager&, int deltaTime) override;
            void destroy(SceneManager&) override;
            void loadEntity() override;
            void unloadEntity() override;
            void update(std::vector<std::shared_ptr<Entity> >& entities);
        protected:
        private:
            GraphicComponent _graph;
    };
}

#endif /* !GRAPHICSYSTEM_HPP_ */
