/*
** EPITECH PROJECT, 2023
** client
** File description:
** EventSystem
*/

#ifndef EVENTSYSTEM_HPP_
#define EVENTSYSTEM_HPP_
#include "ISystem.hpp"

namespace rtype{
    class EventSystem : public ISystem{
        public:
            EventSystem();
            ~EventSystem();
            void init(SceneManager&) override;
            void Update(SceneManager&, int deltaTime) override;
            void destroy(SceneManager&) override;
            void loadEntity() override;
            void unloadEntity() override;
        protected:
        private:
    };
}

#endif /* !EVENTSYSTEM_HPP_ */