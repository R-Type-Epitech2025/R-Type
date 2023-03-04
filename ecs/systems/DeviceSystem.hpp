/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** DeviceSystem
*/

#ifndef DEVICESYSTEM_HPP_
#define DEVICESYSTEM_HPP_

#include <SFML/Graphics.hpp>
#include <ISystem.hpp>

class DeviceSystem {
    public:
        DeviceSystem();
        ~DeviceSystem();

        enum key {
            ESCAPE,
            LEFT,
            RIGHT,
            UP,
            DOWN,
            SHOOT
        };
        void getinput();
    protected:
    private:
};

#endif /* !DEVICESYSTEM_HPP_ */
