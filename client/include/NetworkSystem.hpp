/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** NetworkSystem
*/

#ifndef NETWORKSYSTEM_HPP_
#define NETWORKSYSTEM_HPP_

#include "ISystem.hpp"
#include "Message.hpp"

class MyApp : public QCoreApplication {

    Q_OBJECT
    
    public:
        MyApp(int &argc, char **argv);
        ~MyApp() = default;

    public slots:
        void onReadInput();

    signals:
        void readInput();
};

class NetworkSystem : public ISystem {
    public:
        NetworkSystem();
        ~NetworkSystem();

    protected:
        QByteArray _message;
    private:
};


#endif /* !NETWORKSYSTEM_HPP_ */
