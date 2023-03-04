/*
** EPITECH PROJECT, 2023
** server
** File description:
** Message
*/

#include "Message.hpp"

namespace rtype {
    Message::Message() : _event(PLAYER_EVENT::QUIT), _direction(DIRECTION::UP)
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
        quint32 event;
        quint32 direction;
        in >> event;
        msg._event = static_cast<PLAYER_EVENT>(event);
        if (msg._event == PLAYER_EVENT::MOVE) {
            in >> direction;
            msg._direction = static_cast<DIRECTION>(direction);
        }
        return in;
    }

    PLAYER_EVENT Message::getEvent() const
    {
        return _event;
    }

    DIRECTION Message::getDirection() const
    {
        return static_cast<DIRECTION>(_direction);
    }
}