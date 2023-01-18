/**
 * Project Untitled
 */


#ifndef _ENTITY_H
#define _ENTITY_H

#include "IEntity.h"


class Entity: public IEntity {
public: 
    int ID;
    vector componentList;
private: 
    vector _componentType;
    map _components;
    vector _tags;
};

#endif //_ENTITY_H