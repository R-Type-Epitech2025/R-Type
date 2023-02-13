/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** IScene
*/

#ifndef ISCENE_HPP
#define ISCENE_HPP

#include <map>
#include <memory>
#include <vector>
#include "IEntity.hpp"

namespace rtype
{
    class IScene
    {
    public:
        virtual ~IScene() = default;

        virtual IScene &addEntity(std::shared_ptr<IEntity> entity) = 0;
        // virtual IScene &addEntities(std::vector<std::shared_ptr<IEntity>> entity) = 0;
        virtual void removeEntity(std::shared_ptr<IEntity> entity) = 0;
        virtual std::unique_ptr<IScene> initScene() = 0;

        // virtual std::map<IEntity::Tags, std::vector<std::shared_ptr<IEntity>>> getTaggedEntities(std::vector<IEntity::Tags> tags) = 0;

        // virtual void setAddEntityCallback(std::function<void(std::shared_ptr<IEntity>)> callback) = 0;
        // virtual void setRemoveEntityCallback(std::function<void(std::shared_ptr<IEntity>)> callback) = 0;
        // virtual std::function<void(std::shared_ptr<IEntity>)> getAddEntityCallback() = 0;
        // virtual std::function<void(std::shared_ptr<IEntity>)> getRemoveEntityCallback() = 0;
        // virtual std::vector<std::shared_ptr<IEntity>> &operator[](IEntity::Tags tag) = 0;
    };
}

#endif /* !ISCENE_HPP */
