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
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Game");
    window.setFramerateLimit(60);
    window.clear(sf::Color::Black);

    rtype::Entity entity;
    entity.texture.loadFromFile("../../assets/r-typeBackground.png");

    rtype::Scene scene;
    scene.update(entity, window);

    while(window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.display();
    }

    return 0;
}



