/*
** EPITECH PROJECT, 2023
** Archi
** File description:
** SoundComponent
*/

#ifndef SOUNDCOMPONENT_HPP_
#define SOUNDCOMPONENT_HPP_
#include <SFML/Audio.hpp>
#include <QtNetwork>

namespace rtype{
    class SoundComponent {
        public:

            /**
             ** @brief Construct a new Sound Component object
             ** 
             */
            SoundComponent();

            /**
             ** @brief Destroy the Sound Component object
             ** 
             */
            ~SoundComponent();
            int volume;
        protected:
        private:
    };
}

#endif /* !SOUNDCOMPONENT_HPP_ */
