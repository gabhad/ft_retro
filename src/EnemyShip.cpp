#include "EnemyShip.hpp"

EnemyShip::EnemyShip() 
{
    this->name1 = "u-u";
    this->name2 = "|o|";
    this->name3 = "v v";
    this->positionX = COLS / 2 - 2;
    this->positionY = 3;
    Weapon  *weap = new Weapon(3, -1);
    this->weap = weap;
    this->health = 5;
    this->isDead = 0;
}

EnemyShip::EnemyShip(const EnemyShip &p) : IShip(p) {(void)p;}
EnemyShip &EnemyShip::operator=(const EnemyShip &p) {(void)p; return *this;}

EnemyShip::~EnemyShip() {}

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

void    EnemyShip::moveLeft(void) {
    this->positionX -= 3;
    if (this->positionX <= 1)
        this->positionX = 1;
}

void    EnemyShip::moveRight(void) {
    this->positionX += 3;
    if (this->positionX >= COLS - 7)
        this->positionX = COLS - 7;
}

void    EnemyShip::moveDown(void) {
    this->positionY += 1;
    if (this->positionY >= LINES - 7)
        this->positionY = LINES - 7;
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
