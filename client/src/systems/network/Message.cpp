/*
** EPITECH PROJECT, 2023
** server
** File description:
** Message
*/

#include "Message.hpp"

namespace rtype {
    Message::Message(): _sprites()
    {
    }

    Message::~Message()
    {
    }

    QDataStream &operator>>(QDataStream &in, Message &msg)
    {
        return readMessage(in, msg);
    }

    QDataStream &readMessage(QDataStream &in, Message &msg)
    {
        while (!in.atEnd()) {
            msg._sprites.push_back(nullptr);
        }
        return in;
    }

    std::list<Entity *> Message::getSprites() const
    {
        return _sprites;
    }
}
