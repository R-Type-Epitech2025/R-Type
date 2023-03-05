/*
** EPITECH PROJECT, 2023
** sceneManager
** File description:
** SceneManager
*/

#ifndef SCENEMANAGER_HPP_
#define SCENEMANAGER_HPP_

#include "Scene.hpp"
#include <map>

namespace rtype {
    enum SceneType{
        NONE,
        MAIN_MENU,
        HELP,
        ENDGAME,
        DEATH,
        PAUSE
    };
    class SceneManager : public QObject {

        Q_OBJECT

        public:
            /**
             ** @brief Construct a new Scene Manager object
             ** 
             */
            SceneManager(QObject *parent = nullptr);

            /**
             ** @brief Destroy the Scene Manager object
             ** 
             */
            ~SceneManager();

            /**
             ** @brief get the current scene
             ** 
             ** @param scene 
             */
            const std::string &getScene() const;

            /**
             ** @brief set the current scene
             ** 
             ** @param scene 
             */
            void setScene(std::string scene);

            /**
             ** @brief add a scene to the scene manager
             ** 
             ** @param scene_name 
             ** @param scene 
             */
            void addScene(rtype::Scene *scene);

            /**
             ** @brief Get the Current Scene object
             ** 
             ** @return rtype::Scene* 
             */
            rtype::Scene* getCurrentScene();

            sf::RenderWindow window;
        protected:
            std::map<std::string, rtype::Scene*> _scenes;
            rtype::Scene* _currentscene;
            bool _shouldClose;
        private:
        public slots:
            /**
             ** @brief slot activated when the entities need to be updated
             ** 
             ** @param entities 
             */
            void onUpdateEntities(std::vector<Entity *> entities);
        
        signals:
            /**
             ** @brief signal emitted when the entities need to be updated
             ** 
             ** @param entities 
             */
            void updateEntities(std::vector<Entity *> entities);
    };
};

#endif /* !SCENEMANAGER_HPP_ */
