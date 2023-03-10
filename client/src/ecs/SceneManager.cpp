/*
** EPITECH PROJECT, 2023
** Archi
** File description:
** SceneManager
*/

#include "SceneManager.hpp"
#include "Entity.hpp"
#include <iostream>

namespace rtype {
    SceneManager::SceneManager(QObject *parent) : QObject(parent), window(sf::VideoMode(1920, 1080), "R-Type")
    {
    }

    SceneManager::~SceneManager()
    {
    }

    void SceneManager::setScene(std::string scene)
    {
        this->_currentscene = this->_scenes[scene];
    }

    void SceneManager::addScene(Scene *scene){
        this->_scenes[scene->getSceneName()] = scene;
        QObject::connect(this, SIGNAL(updateEntities(std::vector<EntityCreator_t *>)), scene, SLOT(onUpdateEntities(std::vector<EntityCreator_t *>)));
    }

    Scene* SceneManager::getCurrentScene(){
        // sort(_currentscene->get_entity().begin(), _currentscene->get_entity().end(), [] (Entity *x, Entity *y) { return x->_type < y->_type; });
        return (this->_currentscene);
    }

    void SceneManager::onUpdateEntities(std::vector<EntityCreator_t *> entities)
    {
        emit updateEntities(entities);
    }
}