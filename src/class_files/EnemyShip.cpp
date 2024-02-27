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

int     EnemyShip::getPositionX(void) { return this->positionX; }
int     EnemyShip::getPositionY(void) { return this->positionY; }
int     EnemyShip::getHealth(void) { return this->health; }

void    EnemyShip::printShip(WINDOW *win, const EnemyShip &e) 
{
    if (this->isDead)
        return;
    mvwprintw(win, e.positionY, e.positionX, "%s", this->name1.c_str());
    mvwprintw(win, e.positionY + 1, e.positionX, "%s", this->name2.c_str());
}

int     EnemyShip::shootsMissile(void) { return weap->getDamage(); }

void    EnemyShip::moveDownRight(void) {
    this->positionX += 3;
    this->positionY += 1;
}
void    EnemyShip::moveDownLeft(void) {
    this->positionX -= 3;
    this->positionY += 1;
}

void    EnemyShip::getsDamage(int dmg) {
    this->health -= dmg;
    if (this->health <= 0)
        this->dies();
}

void    EnemyShip::dies(void) 
{
    // XXX coder fonction explosion
    this->isDead = 1;
}

void    EnemyShip::resetCount(void) { this->count = 0; }

int     EnemyShip::count = 0;