/*
** EPITECH PROJECT, 2023
** client
** File description:
** GameSystem
*/

#include "GameSystem.hpp"

namespace rtype{
    GameSystem::GameSystem(QObject *parent) : QObject(parent)
    {
        waves wave1 = {5, false, CreateWave1()};
        waves wave2 = {10, false, CreateWave2()};
        waveContainer.push_back(wave1);
        waveContainer.push_back(wave2);
        bullets = new Entity(EntityType::BULLET, {1920, 0}, {186, 142}, {6, 6}, 2.0, "14.gif", idGenerator());
    }

    GameSystem::~GameSystem()
    {
    }

    void GameSystem::onNewPlayerConnected(quint32 id)
    {
        std::cout << "New player connected with id: " << id << std::endl;
        
        //create player and reset game

    }

    void GameSystem::onPlayerDisconnected(quint32 id)
    {
        std::cout << "Player disconnected with id: " << id << std::endl;
        //delete player
    }

    void GameSystem::onPlayerShoot(quint32 id)
    {
        std::cout << "Player " << id << " shoot" << std::endl;
    }

    void GameSystem::update(SceneManager *sceneManager, uint64_t elapsedTime)
    {
        // std::cout << "Update game" << std::endl;
        // std::cout << "elapsed time: " << elapsedTime << std::endl;
        Scene *scene = sceneManager->getCurrentScene();
        if (scene == nullptr) {
            return;
        }
        for (auto &wave : waveContainer) {
            if (!wave.isLoaded && wave.spawnTime <= elapsedTime) {
                for (auto &entity : wave.wave) {
                    scene->addEntity(entity);
                }
                wave.isLoaded = true;
            }
        }
        // for (auto &entity : scene->getEntities()) {
            // if (entity->container.game_component->health <= 0) {
            //     //SHOULD REMOVE ENTITY
            //     // scene->removeEntity(entity);
            // }
        // }
        // ennemyShoot(scene, elapsedTime);
        emit sendUpdatedEntities(scene->getEntities());
    }

    int GameSystem::idGenerator()
    {
        return id++;
    }

    std::vector<Entity *> GameSystem::CreateWave1()
    {
        std::cout << "create wave 1" << std::endl;
        std::vector<Entity *> entities;
        Entity *entity = new Entity(EntityType::MOB, {0, 0}, {0, 0}, {36, 36}, 3.0, "5.gif", idGenerator());
        for (int i = 0; i < 9; i++) {
            Entity *tmp(new Entity(*entity, idGenerator()));
            
            if (i < 4) {
                tmp->container.movement_component->pos = {1500 - i * 70, 50 + i * 100};
            } else {
                tmp->container.movement_component->pos = {1920 + (i - 4) * 70, 50 + i * 100};
            };
            tmp->container.movement_component->velocity.x = 0;
            tmp->container.game_component->cooldown = 3000;
            entities.push_back(tmp);
        }
        std::cout << "create wave 1 done" << std::endl;
        return entities;
    }
    std::vector<Entity *> GameSystem::CreateWave2()
    {
        std::cout << "create wave 2" << std::endl;
        std::vector<Entity *> entities;
        Entity *entity = new Entity(EntityType::MOB, {1920, 800}, {50, 0}, {50, 50}, 1.5, "14.gif", idGenerator());
        entity->container.movement_component->velocity.x = -5;
        entity->container.graphic_component->counter_sprites = 4;
        entity->container.game_component->cooldown = 1000;
        entities.push_back(entity);
        std::cout << "create wave 2 done" << std::endl;
        return entities;
    }

    // std::vector<Entity *> GameSystem::CreateWave3()
    // {
    //     std::cout << "create wave 3" << std::endl;
    //     std::vector<Entity *> entities;
    //     Entity *entity = new Entity(EntityType::MOB, {1920, 800}, {50, 0}, {50, 50}, 1.5, "14.gif", idGenerator());
    //     entity->container.game_component->cooldown = 1000;
    //     entity->container.game_component->health = 20;
    //     entities.push_back(entity);
    //     std::cout << "create wave 3 done" << std::endl;
    //     return entities;
    // }

    Entity* GameSystem::bulletSpawner(Entity *mob)
    {
        Entity *tmp(new Entity(*this->bullets, idGenerator()));
        tmp->container.movement_component->pos = {mob->container.graphic_component->position.x, mob->container.graphic_component->position.y + 50};
        tmp->container.movement_component->velocity.x = -20;
        return tmp;
    }


    void GameSystem::ennemyShoot(Scene *scene, uint64_t elapsedTime)
    {
        for (auto &entity : scene->getEntities()) {
            if (entity->_type == EntityType::MOB) {
                entity->container.game_component->last_shot += elapsedTime;
                if (entity->container.game_component->last_shot >= entity->container.game_component->cooldown) {
                    scene->addEntity(bulletSpawner(entity));
                    entity->container.game_component->last_shot = 0;
                }
            }
        }
    }
}
