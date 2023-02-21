/*
** EPITECH PROJECT, 2023
** server
** File description:
** Message
*/

#ifndef MESSAGE_HPP_
#define MESSAGE_HPP_

#include <QDataStream>
#include <QNetworkDatagram>

enum EVENT {
    MOVE,
    SHOOT,
    QUIT
};

enum DIRECTION {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Message {
public:
    Message();
    ~Message();

    friend QDataStream &operator>>(QDataStream &in, Message &msg);
    
    quint8 getEvent() const;
    quint8 getDirection() const;

    void print() const;

private:
    friend QDataStream &readMessage(QDataStream &in, Message &msg);

    quint8 _event;
    quint8 _direction;
protected:

};

#endif /* !MESSAGE_HPP_ */
