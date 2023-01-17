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
    QWidget window;
    window.resize(320, 240);
    window.show();
    window.setWindowTitle(
        QApplication::translate("toplevel", "Test"));
    return app.exec();
}

