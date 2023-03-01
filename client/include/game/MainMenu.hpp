/*
** EPITECH PROJECT, 2023
** client
** File description:
** MainMenu
*/

#ifndef MAINMENU_HPP_
#define MAINMENU_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
namespace rtype {
    class MainMenu {
        public:
            MainMenu();
            ~MainMenu();

            int loadFont();
            void createTextButton();


        protected:
        private:
            sf::Font font;
            sf::Event event;
};
};

#endif /* !MAINMENU_HPP_ */
