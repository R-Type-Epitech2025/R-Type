/*
** EPITECH PROJECT, 2023
** server
** File description:
** Message
*/

#ifndef MESSAGE_HPP_
#define MESSAGE_HPP_

#include <iostream>
#include <QDataStream>
#include <QNetworkDatagram>
#include <QtNetwork>
#include <QObject>
#include "ISystem.hpp"
#include <SFML/Graphics.hpp>
#include <list>

namespace rtype {
    namespace system {
        enum EVENT {
            MOVE,
            SHOOT,
            QUIT
        };

        class Message {
        public:
            Message();
            ~Message();

            friend QDataStream &operator>>(QDataStream &in, Message &msg);
            
            std::list<sf::Sprite *> getSprites() const;

        private:
            friend QDataStream &readMessage(QDataStream &in, Message &msg);
            
            std::list<sf::Sprite *> _sprites;
        protected:

        };
    }
}

#endif /* !MESSAGE_HPP_ */
