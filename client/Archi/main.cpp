#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "./Include/SceneManager.hpp"
#include "./Include/Scene.hpp"
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
    sf::RenderWindow window(sf::VideoMode(800, 600), "Mon jeu ECS");
    window.setFramerateLimit(60);
    window.clear(sf::Color::Black);

    Entity entity;
    entity.texture.loadFromFile("background.png");

    RenderSystem renderSystem;
    renderSystem.update(entity, window);

    window.display();

    return 0;
}



