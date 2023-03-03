#include "ISystem.hpp"

namespace rtype {
    class MovementSystem : public QObject {

        Q_OBJECT

    public:
        /**
         * @brief Construct a new Movement System object
         * 
         * @param parent 
         */
        MovementSystem(QObject *parent = nullptr);

        /**
         * @brief Destroy the Movement System object
         * 
         */
        ~MovementSystem() {};

        /**
         * @brief init the movement system
         * 
         * @param scene 
         */
        SystemType getType() const { return SystemType::MOVEMENT; }; 

        // void init(SceneManager &, sf::RenderWindow &) {};

        /**
         * @brief update the movement system
         * 
         * @param scene 
         * @param deltaTime 
         */
        void update(rtype::SceneManager *Manager, sf::Event &event);

        // void destroy() {};
        // void loadEntity(std::shared_ptr<Entity> entity, Scene &scene) {};
        // void unloadEntity(std::shared_ptr<Entity> entity, Scene &scene) {};
    private :
        bool _link;

    signals:
        /**
         * @brief send the move player to the network system
         * 
         * @param dir 
         */
        void sendMovePlayer(DIRECTION dir);

    };
}