/*
** EPITECH PROJECT, 2023
** sceneManager
** File description:
** SceneManager
*/

#ifndef SCENEMANAGER_HPP_
#define SCENEMANAGER_HPP_

#include <iostream>
#include <map>
#include "Scene.hpp"


namespace rtype {
class SceneManager {
    public:
        /**
         * @brief Construct a new Scene Manager object
         * 
         */
        SceneManager();

        /**
         * @brief Destroy the Scene Manager object
         * 
         */
        ~SceneManager();

        /**
         * @brief 
         * 
         * @param scene 
         */
        const std::string &getScene() const;

        /**
         * @brief 
         * 
         * @param scene 
         */
        void setScene(std::string scene);
        void addScene(std::string scene_name, rtype::Scene *scene);

    protected:
        std::map<std::string, rtype::Scene*> _scenes;
        rtype::Scene* _currentscene;
        bool _shouldClose;

    private:
};
};

#endif /* !SCENEMANAGER_HPP_ */
