#pragma once
#include "ISystem.hpp"
#include <memory>
#include <SFML/Graphics.hpp>

class GraphicSystem: 
    public ISystem 
{
    public:
        GraphicSystem();
        ~GraphicSystem();

        void init(SceneManager &sm) final;
        void update(SceneManager &sm, uint64_t deltaTime) final;
        void destroy() final;
        static const sf::RenderWindow &getWindow() {return (window);};

    private:
        static sf::RenderWindow window;
        bool _isInit;
};