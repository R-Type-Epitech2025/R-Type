#include "ISystem.hpp"

namespace rtype {
    class MovementSystem : public QObject {

        Q_OBJECT

    public:
        /**
         ** @brief Construct a new Movement System object
         ** 
         ** @param parent 
         */
        MovementSystem(QObject *parent = nullptr);

        /**
         ** @brief Destroy the Movement System object
         ** 
         */
        ~MovementSystem() {};

        /**
         ** @brief Get the Type object
         ** 
         ** @return SystemType 
         */
        SystemType getType() const { return SystemType::MOVEMENT; }; 

        /**
         ** @brief update the movement system
         ** 
         ** @param Manager 
         ** @param event 
         */
        void update(rtype::SceneManager *Manager, sf::Event &event);
        // void destroy() {};
        // void loadEntity(std::shared_ptr<Entity> entity, Scene &scene) {};
        // void unloadEntity(std::shared_ptr<Entity> entity, Scene &scene) {};
    private :
        bool _link;

    signals:
        /**
         ** @brief send the move player to the network system
         ** 
         ** @param dir 
         */
        void sendMovePlayer(DIRECTION dir);

    public slots:
        /**
         ** @brief receive the move player from the event system
         ** 
         ** @param id
         ** @param dir 
         */
        void onSendMovePlayer(quint32 id, DIRECTION dir);
    };
}