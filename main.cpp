#include <QCoreApplication>
#include <QTimer>
#include <QObject>
#include <QtNetwork>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication game(argc, argv);
    QTimer *timer = new QTimer(&game);

    QObject::connect(timer, &QTimer::timeout, []() {
    std::cout << "Hello World!" << std::endl;
    });
    timer->start(1000);
    return game.exec();
}