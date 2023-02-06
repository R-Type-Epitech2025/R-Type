/*
** EPITECH PROJECT, 2023
** server
** File description:
** main_server
*/

#include "Server.hpp"

int main(int ac, char **av)
{
    if (ac == 2) {
        QCoreApplication app(ac, av);
        QString portstr(av[1]);
        quint16 port = portstr.toUShort();
        Server server(port);
        return app.exec();
    }
    return 84;
}