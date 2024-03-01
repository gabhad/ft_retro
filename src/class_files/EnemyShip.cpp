#include "EnemyShip.hpp"

EnemyShip::EnemyShip() 
{
    this->name1 = "o-o";
    this->name2 = "v v";
    Weapon  *weap = new Weapon(1, -1);
    this->weap = weap;
    this->health = 3;
    this->isDead = 0;

    this->positionX = (count % 10) * ((COLS - 10)/ 9) + 5;
    this->positionY = 5 - (count / 10) * 4;

    count++;
}
EnemyShip::EnemyShip(const EnemyShip &p) : IShip(p) { (void)p; }
EnemyShip &EnemyShip::operator=(const EnemyShip &p) { (void)p; return *this; }

EnemyShip::~EnemyShip() { delete weap; }

int     EnemyShip::getPositionX(void) { return positionX; }
int     EnemyShip::getPositionY(void) { return positionY; }
int     EnemyShip::getHealth(void) { return health; }
int     EnemyShip::getCount(void) { return count; }

void    EnemyShip::printShip(WINDOW *win) 
{
    if (!this->isDead) {
        mvwprintw(win, this->positionY, this->positionX, "%s", this->name1.c_str());
        mvwprintw(win, this->positionY + 1, this->positionX, "%s", this->name2.c_str());
    }
    else if (positionY < LINES) {
        mvwprintw(win, this->positionY, this->positionX, "%s", this->name1.c_str());
        mvwprintw(win, this->positionY + 1, this->positionX, "%s", this->name2.c_str());
    }

}

int     EnemyShip::shootsMissile(void) { 
    if (time(nullptr) - this->lastShot < 2 || time(nullptr) - this->lastShot < 1 || !weap->getAmmo())
        return 0;
    if (std::rand() % 40 == 0) {
        this->weap->shoots();
        this->lastShot = time(nullptr);
        return weap->getDamage();
    }
    return 0;

 }

void    EnemyShip::moveDownRight(void) {
    if (!isDead) {
        positionX += 3;
        positionY += 1;
    }
    else {
        if (positionY <= LINES)
            positionY += 5;
    }

}
void    EnemyShip::moveDownLeft(void) {
    if (!isDead) {
        positionX -= 3;
        positionY += 1;
    }
    else
        if (positionY <= LINES)
            positionY += 5;
}

void    EnemyShip::getsDamage(int dmg) {
    this->health -= dmg;
    if (this->health <= 0)
        this->dies();
}

void    EnemyShip::dies(void) 
{
    isDead = 1;
    name1 = "***";
    name2 = "***";
    count -= 1;
}

void    EnemyShip::resetCount(void) { this->count = 0; }

int     EnemyShip::count = 0;