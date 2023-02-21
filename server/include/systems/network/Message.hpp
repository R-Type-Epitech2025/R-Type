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
#include <list>
#include "Sprite.hpp"

namespace rtype {
    namespace server {
        
        enum EVENT {
            MOVE,
            SHOOT,
            QUIT,
            CONNECT,
            DISCONNECT
        };

        enum DIRECTION {
            UP,
            DOWN,
            LEFT,
            RIGHT
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
            ** @brief Get the Id object
            ** 
            ** @return quint16 the id of the player who sent the message
            */
            quint16 getId() const;

            /*
            ** @brief Get the Event sent by the player
            ** 
            ** @return EVENT the event sent by the player
            */
            EVENT getEvent() const;

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
            
            quint16 _id;
            quint8 _event;
            quint8 _direction;
            QString _ip;
            quint16 _port;
        protected:

        };
    }
}

#endif /* !MESSAGE_HPP_ */
