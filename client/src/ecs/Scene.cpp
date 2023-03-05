/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Scene
*/

#include "Scene.hpp"
#include <iostream>


namespace rtype {
    Scene::Scene(std::string sceneName): QObject(nullptr)
    {
        _sceneName = sceneName;
    }

    Scene::~Scene()
    {
    }

    void Scene::addEntity(Entity *entity)
    {
        _entities.push_back(entity);
        //std::sort(_entities.begin(), _entities.end());
    }   

    std::vector<Entity*> Scene::get_entities(){
        return(_entities);
    }

    Entity *Scene::getEntity(quint32 id) {
        for (auto &entity : _entities) {
            if (entity->_id == id)
                return (entity);
        }
        return (nullptr);
    }

    void Scene::removeEntity(Entity *entity)
    {
        for (auto it = _entities.begin(); it != _entities.end(); it++) {
            if (*it == entity) {
                _entities.erase(it);
                break;
            }
        }
    }

    std::string Scene::getSceneName() const
    {
        return (_sceneName);
    }

    void Scene::onUpdateEntities(std::vector<EntityCreator_t *> entitiesCreator)
    {
        bool found = false;

        for (int i = 0; i < _entities.size(); i++) {
            found = false;
            for (int j = 0; j < entitiesCreator.size(); j++) {
                if (_entities[i]->_id == entitiesCreator[j]->id) {
                    found = true;
                    updateEntity(_entities[i], entitiesCreator[j]);
                    removeEntityCreator(entitiesCreator, j);
                    break;
                }
            }
            if (!found) {
                removeEntity(_entities[i]);
                i--;
            }
        }
        for (int i = 0; i < entitiesCreator.size(); i++) {
            updateTexture(entitiesCreator[i]->spriteName);
            createEntity(entitiesCreator[i]);
        }
    }

    void Scene::updateTexture(std::string spriteName)
    {
        if (textures.find(spriteName) == textures.end()) {
            sf::Texture texture;
            texture.loadFromFile(spriteName);
            textures[spriteName] = texture;
        }
    }

    void Scene::createEntity(EntityCreator_t *entityCreator)
    {
        Entity *entity = new Entity(EntityType::MOB, entityCreator->positionInScreen, entityCreator->posSheet, entityCreator->sizeSheet, entityCreator->scale, entityCreator->spriteName, entityCreator->id);
        addEntity(entity);
    }

    void Scene::removeEntityCreator(std::vector<EntityCreator_t *> &entitiesCreator, int index)
    {
        for (int i = index; i < entitiesCreator.size() - 1; i++) {
            entitiesCreator[i] = entitiesCreator[i + 1];
        }
        entitiesCreator.pop_back();
    }

    void Scene::updateEntity(Entity *entity, EntityCreator_t *entityCreator)
    {
        entity->update(entityCreator);
    }


}

// void update(Entity& entity, sf::RenderWindow& window) {
//         sf::Sprite sprite(entity.texture);
//         sprite.setPosition(entity.position);
//         window.draw(sprite);
// }

// void Scene::draw(sf::RenderWindow& window)
// {
// //    for (auto& entity : entities) {
// //         sf::Sprite sprite(entity.texture);
// //         sprite.setPosition(entity.position);
// //         window.draw(sprite);
// //     }
// }

// void Scene::getScene(std::vector<IScene> scene)
// {
//     // for (auto& entity : entities) {
//     //     sf::Sprite sprite(entity.texture);
//     //     sprite.setPosition(entity.position);
//     //     window.draw(sprite);
//     // }
// }

