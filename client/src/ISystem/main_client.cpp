/*
** EPITECH PROJECT, 2023
** server
** File description:
** main
*/

#include "Client.hpp"

int main(int ac, char **av)
{
    if (ac == 3) {
        MyApp app(ac, av);
        QString ip(av[1]);
        QString portstr(av[2]);
        quint16 port = portstr.toUShort();
        Client client(nullptr, ip, port);
        emit app.readInput();
        return app.exec();
    }
    return 84;
}