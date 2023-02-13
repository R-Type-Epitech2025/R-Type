/*
** EPITECH PROJECT, 2023
** server
** File description:
** Message
*/

#include "Message.hpp"

Message::Message()
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
    in >> msg._event;
    in >> msg._direction;
    return in;
}

quint8 Message::getEvent() const
{
    return _event;
}

quint8 Message::getDirection() const
{
    return _direction;
}