/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** client
*/

#include <iostream>
#include <QtNetwork>
#include <QtCore>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QHostAddress address("127.0.0.1");
    return app.exec();
}

