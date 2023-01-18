/**
 * Project Untitled
 */


#ifndef _ISYSTEM_H
#define _ISYSTEM_H

class ISystem {
public: 
    
/**
 * @param SceneManager&
 */
void init(void SceneManager&);
    
/**
 * @param SceneManager&
 * @param deltaTime
 */
void Update(void SceneManager&, void deltaTime);
    
/**
 * @param SceneManager&
 */
void destroy(void SceneManager&);
    
void loadEntity();
    
void UnloadEntity();
};

#endif //_ISYSTEM_H