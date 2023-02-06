/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_



namespace rtype {
    class Player {
        public:
            Player();
            Player(sf::Texture&);
            ~Player();
            void moveUp();
            void moveLeft();
            void moveRight();
            void moveDown();

        protected:
        private:
            sf::Sprite _Sprite; //Declare Player Sprite
            sf::Vector2i _Source; //Declare Source (Sprite Sheet Crop)
            float _Speed; //Player Speed
    };
}
#endif /* !PLAYER_HPP_ */
