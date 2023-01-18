/**
 * Project Untitled
 */


#ifndef _SCENEMANAGER_H
#define _SCENEMANAGER_H

#include "ISystem.h"


class SceneManager: public ISystem {
private: 
    map _scenes;
    SceneType _currentScene;
    bool shouldClose;
};

#endif //_SCENEMANAGER_H