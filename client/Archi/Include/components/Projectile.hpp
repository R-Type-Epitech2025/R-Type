/*
** EPITECH PROJECT, 2023
** client
** File description:
** Projectile
*/

#ifndef PROJECTILE_HPP_
#define PROJECTILE_HPP_

class Projectile : public Component {
    public:
        enum class Type {
            Shoot1,
            Shoot2,
            Shoot3,
            etc
        };

        /**
         * @brief Construct a new Projectile object
         * 
         * @param byPlayer 
         */
        Projectile(bool byPlayer);

        /**
         * @brief Destroy the Projectile object
         * 
         */
        ~Projectile();

        /**
         * @brief Is it the player who shoot ?
         * 
         * @return true 
         * @return false 
         */
        bool PlayerShoot() {return(byPlayer);};

        /**
         * @brief Check if the projectile is launched
         * 
         * @param _isLaunched 
         * @return true 
         * @return false 
         */
        bool SetIsLaunched(bool _isLaunched) {isLaunched = _isLaunched;};

        /**
         * @brief Get if the projectile is launched
         * 
         * @return true 
         * @return false 
         */
        bool GetIsLaunched() {return(isLaunched);};

        /**
         * @brief Get the Type of the projectile
         * 
         * @return Type 
         */
        Type GetType() {return(type);};

        /**
         * @brief Set the type of the projectile
         * 
         * @param _type 
         */
        void SetType(Type _type) {type = _type;};

        /**
         * @brief Set the Shooting angle of the projectile
         * 
         */
        void SetAngle();

        /**
         * @brief set the next time the projectile can be shoot
         * 
         */
        void NextTimeSended();

        /**
         * @brief get the time when the projectile was launched
         * 
         * @return int 
         */
        int GetTimesended() {return(timesended);};

        
    protected:
    private:
        bool byPlayer;
        bool isLaunched;
        Type type;
        int timesended;
};

#endif /* !PROJECTILE_HPP_ */
