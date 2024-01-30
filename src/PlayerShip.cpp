#include "PlayerShip.hpp"

        PlayerShip::PlayerShip(void) {}
        PlayerShip::PlayerShip(const PlayerShip &p) {}
        PlayerShip &PlayerShip::operator=(const PlayerShip &p) {}

        void PlayerShip::shoot(void) {}

        void PlayerShip::gets_damage(int dmg) {
            this->health -= dmg;
            if (this->health <= 0) {
                // XXX definir game over
            }
        }
