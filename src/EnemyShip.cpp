#include "EnemyShip.hpp"

EnemyShip::EnemyShip() 
{
    this->name1 = "u-u";
    this->name2 = "|o|";
    this->name3 = "v v";
    Weapon  *weap = new Weapon(3, -1);
    this->weap = weap;
    this->health = 5;
    this->isDead = 0;

    this->positionX = (count % 5) * (COLS / 5) + 5;
    this->positionY = 11 - (count / 5) * 5;

    count++;
}

EnemyShip::EnemyShip(const EnemyShip &p) : IShip(p) {(void)p;}
EnemyShip &EnemyShip::operator=(const EnemyShip &p) {(void)p; return *this;}

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
    mvwprintw(win, e.positionY + 2, e.positionX, "%s", this->name3.c_str());
}

void    EnemyShip::shootsMissile(void)
{
    this->weap->shoots(this->weap->getDamage(), "DOWN", this->positionX, this->positionY);
}

void    EnemyShip::moveDownRight(void) {
    this->positionX += 2;
    this->positionY += 2;
}
void    EnemyShip::moveDownLeft(void) {
    this->positionX -= 2;
    this->positionY += 2;
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

int     EnemyShip::count = 0;