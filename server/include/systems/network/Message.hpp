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
#include <SFML/Graphics.hpp>
#include "ISystem.hpp"

namespace rtype {

    /**
     ** @brief The event sent by the player
     ** 
     */
    enum class PLAYER_EVENT {
        MOVE,
        SHOOT,
        QUIT,
        CONNECT
    };

    class Message {
    public:

        /**
         ** @brief Construct a new Message object
         ** 
         */
        Message();

        /**
         ** @brief Destroy the Message object
         ** 
         */
        ~Message();

        /**
         ** @brief Construct a new Message object
         ** 
         ** @param in 
         ** @param msg 
         ** @return QDataStream& 
         */
        friend QDataStream &operator>>(QDataStream &in, Message &msg);

        /**
         ** @brief Get the Event object
         ** 
         ** @return PLAYER_EVENT 
         */
        PLAYER_EVENT getEvent() const;

        /**
         ** @brief Get the Direction object
         ** 
         ** @return DIRECTION 
         */
        DIRECTION getDirection() const;

    private:
        /**
         ** @brief Read the message
         ** 
         ** @param in 
         ** @param msg 
         ** @return QDataStream& 
         */
        friend QDataStream &readMessage(QDataStream &in, Message &msg);

        PLAYER_EVENT _event;
        DIRECTION _direction;
    protected:

    };
}

#endif /* !MESSAGE_HPP_ */
