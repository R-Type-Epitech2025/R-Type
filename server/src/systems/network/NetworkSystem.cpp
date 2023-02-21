/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** NetworkSystem
*/

#include "NetworkSystem.hpp"

// NETWORK SYSTEM
namespace rtype {
    namespace server {
        NetworkSystem::NetworkSystem()
        {
        }

        NetworkSystem::~NetworkSystem()
        {
        }

        // QCOREAPP : FUTURE GAME LOOP

        // MyApp::MyApp(int &argc, char **argv): QCoreApplication(argc, argv)
        // {
        //     connect(this, &MyApp::readInput, this, &MyApp::onReadInput, Qt::QueuedConnection);
        // }

        // void MyApp::onReadInput()
        // {
        //     std::string input;
        //     std::getline(std::cin, input);
        //     if (input == "exit")
        //         quit();
        //     else {
        //         emit readInput();
        //     }
        // }
    }
}
