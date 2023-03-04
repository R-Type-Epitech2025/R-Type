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
        float scale = scale_decimal / 100;
        quint32 x;
        quint32 y;
        std::string name;

        while (!in.atEnd()) {
            in >> id >> entityType >> spritesheetIndex >> x_sheet >> y_sheet >> width_sheet >> height_sheet >> scale >> x >> y;
            name = "./assets/" + std::to_string(spritesheetIndex) + ".png";

            msg._entities.push_back(new Entity(convertUint32ToEntityType(entityType), {(int) (x - (width_sheet * scale)), (int) (y - (height_sheet * scale))}, {(int) x_sheet, (int) y_sheet}, { (int) width_sheet, (int) height_sheet}, scale, name, id));
        }
        return in;
    }

    std::vector<Entity *> Message::getEntities() const
    {
        return _entities;
    }
}