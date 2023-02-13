/*
** EPITECH PROJECT, 2023
** client
** File description:
** AudioSystem
*/

#ifndef AUDIOSYSTEM_HPP_
#define AUDIOSYSTEM_HPP_
#include "ISystem.hpp"

namespace rtype{
    class AudioSystem : public ISystem{
        public:
            AudioSystem();
            ~AudioSystem();
            void initAudio();
            void setVolume();
            bool isReady();
            int getMainVolume();
        protected:
        private:
    };
}

#endif /* !AUDIOSYSTEM_HPP_ */
