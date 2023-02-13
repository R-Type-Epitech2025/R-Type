/*
** EPITECH PROJECT, 2023
** client
** File description:
** ISystem
*/

#ifndef ISYSTEM_HPP_
#define ISYSTEM_HPP_
#include "SceneManager.hpp"

namespace rtype{
    enum SystemType{
        GAME,
        GRAPHIQUE,
        EVENT,
        PARTICLE,
        COLLIDE,
        AUDIO,
        NETWORK
    };

    class ISystem {
        public:
            ISystem();
            ~ISystem();
            virtual void init(SceneManager&) = 0;
            virtual void Update(SceneManager&, int deltaTime) = 0;
            virtual void destroy(SceneManager&) = 0;
            virtual void loadEntity() = 0;
            virtual void unloadEntity() = 0;
        protected:
        private:
    };
}

#endif /* !ISYSTEM_HPP_ */
