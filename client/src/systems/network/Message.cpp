/*
** EPITECH PROJECT, 2023
** server
** File description:
** Message
*/

#include "Message.hpp"

namespace rtype {
    Message::Message(): _entities()
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
        quint32 id;
        quint32 entityType;
        quint32 spritesheetIndex;
        quint32 x_sheet;
        quint32 y_sheet;
        quint32 width_sheet;
        quint32 height_sheet;
        quint32 scale_decimal;
        quint32 x;
        quint32 y;
        std::string name;
        EntityCreator_t *entity;
 
        while (!in.atEnd()) {
            in >> id >> entityType >> spritesheetIndex >> x_sheet >> y_sheet >> width_sheet >> height_sheet >> scale_decimal >> x >> y;
            name = "./assets/r-typesheet" + std::to_string(spritesheetIndex) + ".gif";

            float scale = (float) scale_decimal;
            entity = new EntityCreator_t;
            entity->positionInScreen = {(int) (x - (width_sheet * scale)), (int) (y - (height_sheet * scale))};
            entity->posSheet = {(int) x_sheet, (int) y_sheet};
            entity->sizeSheet = {(int) width_sheet, (int) height_sheet};
            entity->scale = scale;
            entity->spriteName = name;
            entity->id = id;
            msg._entities.push_back(entity);
        }
        return in;
    }

    std::vector<EntityCreator_t *> Message::getEntities() const
    {
        return _entities;
    }
}