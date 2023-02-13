//#include <SFML/Graphics.hpp>

//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//        window.clear();
//        window.display();
//    }
//    return 0;
//}

#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>

int main(int argc, char **argv)
{
 QApplication app (argc, argv);

 QPushButton button ("Hello world !");
 button.show();

 return app.exec();
}