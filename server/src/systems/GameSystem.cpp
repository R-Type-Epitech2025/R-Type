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
        clock = new QElapsedTimer();
        waves wave1 = {5, false, CreateWave1()};
        waves wave2 = {10, false, CreateWave2()};
        waveContainer.push_back(wave1);
        waveContainer.push_back(wave2);
        players = {0, false, {}};
        bullets = new Entity(EntityType::BULLET, {1920, 0}, {186, 142}, {6, 6}, 2.0, "14.gif", idGenerator());
    }

    GameSystem::~GameSystem()
    {
    }

    void GameSystem::onNewPlayerConnected(quint32 id)
    {
        std::cout << "New player connected with id: " << id << std::endl;
        //work but somehow, crash with more than one player...
        players.wave.push_back(new Entity(EntityType::PLAYER, {100, 500}, {1, (3 + 17 * (int)players.wave.size())}, {32, 14}, 2.0, "42.gif", id));
        for (auto &wave : waveContainer) {
            wave.isLoaded = false;
        }
        for (auto &entity : players.wave) {
            entity->container.movement_component->pos = {100, 500};
        }
        players.isLoaded = false;
        waveContainer[0].isLoaded = false;
        waveContainer[1].isLoaded = false;
        waveContainer[0].wave = CreateWave1();
        waveContainer[1].wave = CreateWave2();
        clock->start();

    }

    void GameSystem::onPlayerDisconnected(quint32 id)
    {
        std::cout << "Player disconnected with id: " << id << std::endl;
        //need to test
        for (auto &entity : players.wave) {
            if (entity->_id == id) {
                players.wave.erase(std::remove(players.wave.begin(), players.wave.end(), entity), players.wave.end());
                break;
            }
        }
    }

    void GameSystem::onPlayerShoot(quint32 id)
    {
        std::cout << "Player " << id << " shoot" << std::endl;
    }

    void GameSystem::update(SceneManager *sceneManager)
    {
        if (players.wave.size() == 0) {
            return;
        }
        uint64_t elapsedTime = clock->elapsed();
        Scene *scene = sceneManager->getCurrentScene();
        if (scene == nullptr) {
            return;
        }
        if (players.isLoaded == false) {
            for (auto &player : players.wave) {
                scene->addEntity(player);
            }
            players.isLoaded = true;
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
                tmp->container.movement_component->pos = {2200 - i * 70, 50 + i * 100};
            } else {
                tmp->container.movement_component->pos = {1920 + (i - 4) * 70, 50 + i * 100};
            };
            tmp->container.movement_component->velocity.x = -10;
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
                if (entity->container.game_component->last_shot + entity->container.game_component->cooldown <= elapsedTime) {
                    std::cout << "shoot" << std::endl;
                    scene->addEntity(bulletSpawner(entity));
                    entity->container.game_component->last_shot = elapsedTime;
                }
            }
        }
    }
}
