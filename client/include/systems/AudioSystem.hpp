/*
** EPITECH PROJECT, 2023
** client
** File description:
** AudioSystem
*/

#ifndef AUDIOSYSTEM_HPP_
#define AUDIOSYSTEM_HPP_

namespace rtype{
    class AudioSystem : public ISystem{
        public:
            /**
             ** @brief Construct a new Audio System object
             ** 
             */
            AudioSystem();

            /**
             ** @brief Destroy the Audio System object
             ** 
             */
            ~AudioSystem();

            /**
             ** @brief init audio
             ** 
             */
            void initAudio();

            /**
             ** @brief Set the Volume object
             ** 
             */
            void setVolume();

            /**
             ** @brief check if audio is ready
             ** 
             ** @return true 
             ** @return false 
             */
            bool isReady();

            /**
             ** @brief get main volume
             ** 
             ** @return int 
             */
            int getMainVolume();
        protected:
        private:
    };
}

#endif /* !AUDIOSYSTEM_HPP_ */
