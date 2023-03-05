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
    /**
     ** @brief enum of events connard 
     ** 
     */
    enum class EVENT {
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
         ** @brief gives acces to the private members 
         ** 
         ** @param in 
         ** @param msg 
         ** @return QDataStream& 
         */
        friend QDataStream &operator>>(QDataStream &in, Message &msg);
        
        /**
         ** @brief Get the Entities object
         ** 
         ** @return std::vector<Entity *> 
         */
        std::vector<EntityCreator_t *> getEntities() const;

    private:
        /**
         ** @brief get the message in the datastream and writes it in the message
         ** 
         ** @param in 
         ** @param msg 
         ** @return QDataStream& the rest of the datastream voila, pfiou... c'est tout
         */
        friend QDataStream &readMessage(QDataStream &in, Message &msg);
        
        std::vector<EntityCreator_t *> _entities;
    protected:

    };
}

#endif /* !MESSAGE_HPP_ */
