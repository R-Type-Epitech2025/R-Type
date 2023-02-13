/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** ISystem
*/

#ifndef ISYSTEM_HPP_
#define ISYSTEM_HPP_

#include <QtNetwork>
#include <QtCore>
#include <iostream>
#include <string>

class ISystem {
    public:
        ISystem();
        ~ISystem();

        void init();
        void update();
        void destroy();
    protected:
    private:
};

#endif /* !ISYSTEM_HPP_ */
