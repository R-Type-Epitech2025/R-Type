/*
** EPITECH PROJECT, 2023
** Archi
** File description:
** SceneManager
*/

#include "ecs/SceneManager.hpp"
#include "ecs/Entity.hpp"
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
        QObject::connect(this, SIGNAL(updateEntities(std::vector<Entity *>)), scene, SLOT(onUpdateEntities(std::vector<Entity *>)));
    }

    Scene* SceneManager::getCurrentScene(){
        // sort(_currentscene->get_entity().begin(), _currentscene->get_entity().end(), [] (rtype::Entity *x, rtype::Entity *y) { return x->_type < y->_type; });
        return (this->_currentscene);
    }

    void SceneManager::onUpdateEntities(std::vector<Entity *> entities)
    {
        emit updateEntities(entities);
    }
}