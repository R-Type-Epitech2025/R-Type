/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Entity
*/
#ifndef ENTITY_HPP_
#define ENTITY_HPP_
#include <QtCore>

namespace rtype {
    class Entity : public QObject {
    private:
        /* data */
    public:

        struct Entity_Mouvement {
                int index;
                int x_Coordinate;
                int y_Coordinate;
                int sprit_width;
                int sprit_height;
            };
        enum DIRECTION {
                UP,
                DOWN,
                LEFT,
                RIGHT
        };
        int x;
        int y;
        bool Player;
        Entity();
        void setPosition(int x, int y);
        public slots:
            void onNewData(Entity_Mouvement Mouvement);
        signals:
            void new_data(DIRECTION Direction);
       
        
    };
    
}
#endif /* !ENTITY_HPP_ */