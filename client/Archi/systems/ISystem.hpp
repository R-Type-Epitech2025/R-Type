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
            void init(SceneManager&);
            void Update(SceneManager&, int deltaTime);
            void destroy(SceneManager&);
            void loadEntity();
            void unloadEntity();
        protected:
        private:
    };
}

#endif /* !ISYSTEM_HPP_ */
