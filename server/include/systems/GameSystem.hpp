/*
** EPITECH PROJECT, 2023
** client
** File description:
** GameSystem
*/

#ifndef GAMESYSTEM_HPP_
#define GAMESYSTEM_HPP_

#include "ISystem.hpp"

namespace rtype{
class GameSystem : public QObject {

    Q_OBJECT

    public:
        GameSystem(QObject *parent = nullptr);
        ~GameSystem();

    public slots:
        void onNewPlayerConnected(quint16 id);
    protected:
    private:
        GameComponent _game;
};
}

#endif /* !GAMESYSTEM_HPP_ */
