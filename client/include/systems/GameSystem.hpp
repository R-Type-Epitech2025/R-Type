/*
** EPITECH PROJECT, 2023
** client
** File description:
** GameSystem
*/

#ifndef GAMESYSTEM_HPP_
#define GAMESYSTEM_HPP_

#include "ISystem.hpp"

namespace rtype{
class GameSystem : public ISystem {
    public:

        /**
         * @brief Construct a new Game System object
         * 
         */
        GameSystem();

        /**
         * @brief Destroy the Game System object
         * 
         */
        ~GameSystem();

        /**
         * @brief init game
         * 
         * @param SceneManager 
         */
        void init(SceneManager&) override;

        /**
         * @brief update game
         * 
         * @param SceneManager 
         * @param deltaTime 
         */
        void Update(SceneManager&, int deltaTime) override;

        /**
         * @brief destroy game
         * 
         * @param SceneManager 
         */
        void destroy(SceneManager&) override;

        /**
         * @brief load game
         * 
         */
        void loadEntity() override;

        /**
         * @brief unload game
         * 
         */
        void unloadEntity() override;
    protected:
    private:
        GameComponent _game;
};
}

#endif /* !GAMESYSTEM_HPP_ */
