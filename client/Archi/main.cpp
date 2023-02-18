#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "./Include/SceneManager.hpp"
#include "./Include/IScene.hpp"
#include "./Include/IEntity.hpp"
#include "./Include/Entity.hpp"
#include "./Include/Scene.hpp"
#include "./Include/components/IComponent.hpp"
#include "./Include/systems/GraphicSystem.hpp"
#include <map>


// int main(void) {

//     sf::RenderWindow window(sf::VideoMode(800, 600), "My Game");
//     rtype::SceneManager *sceneManager = new rtype::SceneManager();
//     // this.getscene(setScene("mainMenu"))[rtype::SceneType::MAIN_MENU] = new rtype::Scene();
//     while(window.isOpen()){
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//                 window.close();
//         }
//         window.clear();
//         window.display();
//     }
// }   

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Game");
    window.setFramerateLimit(60);
    window.clear(sf::Color::Black);
    rtype::GraphicSystem *graphic = new rtype::GraphicSystem();
    rtype::Entity *entity = new rtype::Entity();
    entity->add_Container(rtype::ComponentType::GameComponent);
    entity->add_Container(rtype::ComponentType::GraphicComponent);
    entity->add_Container(rtype::ComponentType::MovemementComponent);
    entity->container.graphic_component->createSprite("./Archi/assets/pacman.png", 100, 100);
    entity->container.graphic_component->setPosition(0, 0);
    entity->test = "test";
    rtype::Scene *scene = new rtype::Scene();
    scene->addEntity(entity);
    scene->test = "caca";
    rtype::SceneManager *sceneManager = new rtype::SceneManager();
    sceneManager->addScene("first", scene);
    sceneManager->setScene("first");

    while(window.isOpen()){
        sf::Event event;
        rtype::Scene *scene = sceneManager->getCurrentScene();
        while (window.pollEvent(event))
        {
            graphic->Update(sceneManager, 12, window);
            if (event.type == sf::Event::Closed)
                window.close();
            window.clear();
        }
    }

    return 0;
}



