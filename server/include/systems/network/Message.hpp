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
#include <QtNetwork>
#include <SFML/Graphics.hpp>
#include "ISystem.hpp"

namespace rtype {
        
    enum class PLAYER_EVENT {
        MOVE,
        SHOOT,
        QUIT,
        CONNECT
    };

    class Message {
    public:

        /*
        ** @brief Construct a new Message object
        ** 
        */
        Message();

        /*
        ** @brief Destroy the Message object
        ** 
        */
        ~Message();

        /*
        ** @brief Deserialize the message
        ** 
        ** @param in the QDataStream to Deserialize the message to
        ** @param msg the message to deserialize
        ** @return QDataStream& the unused part of the QDataStream
        */
        friend QDataStream &operator>>(QDataStream &in, Message &msg);

        /*
        ** @brief Get the Event sent by the player
        ** 
        ** @return EVENT the event sent by the player
        */
        PLAYER_EVENT getEvent() const;

        /*
        ** @brief Get the Direction of the move event
        ** 
        ** @return DIRECTION the direction of the move event
        */
        DIRECTION getDirection() const;

    private:
        /*
        ** @brief Read the message from the QDataStream
        ** 
        ** @param in the QDataStream to read the message from
        ** @param msg the message to read
        ** @return QDataStream& the unused part of the QDataStream
        */
        friend QDataStream &readMessage(QDataStream &in, Message &msg);

        PLAYER_EVENT _event;
        DIRECTION _direction;
    protected:

    };
}

#endif /* !MESSAGE_HPP_ */
