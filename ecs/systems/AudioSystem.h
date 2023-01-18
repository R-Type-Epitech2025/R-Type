/**
 * Project Untitled
 */


#ifndef _AUDIOSYSTEM_H
#define _AUDIOSYSTEM_H

#include "ISystem.h"


class AudioSystem: public ISystem {
public: 
    
void audioSystem();
    
void initAudio();
    
void setVolume();
    
void isReady();
    
void getMainVolume();
};

#endif //_AUDIOSYSTEM_H