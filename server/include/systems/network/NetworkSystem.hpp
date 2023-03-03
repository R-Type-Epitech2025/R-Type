/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** NetworkSystem
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include "UDPSocket.hpp"

namespace rtype{
    
    class NetworkSystem : public QObject {

        Q_OBJECT

        public:
            NetworkSystem(QObject *parent, QString addr, quint32 port);
            ~NetworkSystem() {};

            SystemType getType();
            // void init(SceneManager &sceneManager) {};
            // void update(SceneManager &manager, uint64_t time) {};
            // void destroy() {};
            // void loadEntity(std::shared_ptr<Entity> entity, Scene &scene) {};
            // void unloadEntity(std::shared_ptr<Entity> entity, Scene &scene) {};

        public slots:
            void onSendMovePlayer(rtype::DIRECTION dir);
            void onMessageReceived(Message &msg);

        signals:
            void updateSprites(std::list<Entity *> sprites);

        protected:
        private:
            UDPSocket *_udpSocket;
    };
}

#endif /* !CLIENT_HPP_ */
