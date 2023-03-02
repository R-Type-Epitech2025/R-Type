#include "ISystem.hpp"

namespace rtype {
    class MovementSystem : public QObject {

        Q_OBJECT

    public:
        MovementSystem(QObject *parent = nullptr);
        ~MovementSystem() {};
        SystemType getType() const { return SystemType::MOVEMENT; }; 
        // void init(SceneManager &, sf::RenderWindow &) {};
        void update(rtype::SceneManager *Manager, sf::Event &event);
        // void destroy() {};
        // void loadEntity(std::shared_ptr<Entity> entity, Scene &scene) {};
        // void unloadEntity(std::shared_ptr<Entity> entity, Scene &scene) {};
    private :
        bool _link;

    signals:
        void sendMovePlayer(DIRECTION dir);

    };
}