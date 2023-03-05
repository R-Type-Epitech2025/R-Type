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
        std::vector <waves> waveContainer = {wave1, wave2};
        bullets = new Entity(EntityType::BULLET, {1920, 0}, {16, 240}, {16, 16}, 2.0, "./assets/sprites.png", idGenerator());
    }

    GameSystem::~GameSystem()
    {
    }

    void GameSystem::onNewPlayerConnected(quint32 id)
    {
        std::cout << "New player connected with id: " << id << std::endl;
    }

    void GameSystem::onPlayerDisconnected(quint32 id)
    {
        std::cout << "Player disconnected with id: " << id << std::endl;
    }

    void GameSystem::onPlayerShoot(quint32 id)
    {
        std::cout << "Player " << id << " shoot" << std::endl;
    }

    void GameSystem::update(SceneManager *sceneManager, uint64_t elapsedTime)
    {
        std::cout << "Update game" << std::endl;
    }

    int GameSystem::idGenerator()
    {
        return id++;
    }

    std::vector<Entity *> GameSystem::CreateWave1()
    {
        std::cout << "create wave 1" << std::endl;
        std::vector<Entity *> entities;
        Entity *entity = new Entity(EntityType::MOB, {0, 0}, {0, 0}, {36, 36}, 3.0, "./assets/ennemy1.gif", idGenerator());
        for (int i = 0; i < 9; i++) {
            Entity *tmp(new Entity(*entity));
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
        Entity *entity = new Entity(EntityType::MOB, {1920, 800}, {50, 0}, {50, 50}, 1.5, "./assets/ennemy2.gif", idGenerator());
        entity->container.movement_component->velocity.x = -5;
        entity->container.graphic_component->counter_sprites = 4;
        entity->container.game_component->cooldown = 1000;
        entities.push_back(entity);
        std::cout << "create wave 2 done" << std::endl;
        return entities;
    }

    Entity* GameSystem::bulletSpawner(Entity *mob)
    {
        Entity *tmp(new Entity(*this->bullets));
        tmp->container.movement_component->pos = {mob->container.graphic_component->position.x, mob->container.graphic_component->position.y + 50};
        tmp->container.movement_component->velocity.x = -20;
        return tmp;
    }


    void GameSystem::ennemyShoot(Scene *scene, uint64_t elapsedTime)
    {
        for (auto &entity : scene->get_entities()) {
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
