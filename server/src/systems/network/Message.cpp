/*
** EPITECH PROJECT, 2023
** server
** File description:
** Message
*/

#include "Message.hpp"

namespace rtype {
    Message::Message(): _id(0), _event(0), _direction(0)
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
        in >> msg._id;
        in >> msg._event;
        if (msg._event == EVENT::MOVE)
            in >> msg._direction;
        return in;
    }

    quint16 Message::getId() const
    {
        return _id;
    }

    EVENT Message::getEvent() const
    {
        return static_cast<EVENT>(_event);
    }

    DIRECTION Message::getDirection() const
    {
        return static_cast<DIRECTION>(_direction);
    }
}
