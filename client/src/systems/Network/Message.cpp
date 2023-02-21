/*
** EPITECH PROJECT, 2023
** server
** File description:
** Message
*/

#include "Message.hpp"

namespace rtype {
    namespace system {
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
                msg._sprites.push_back(new Sprite(in));
            }
        }

        std::list<job_dsl copy *> Message::getSprites() const
        {
            return _sprites;
        }
    }
}
