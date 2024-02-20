#include "PlayerShip.hpp"

PlayerShip::PlayerShip() {
    this->name1 = "^ ^";
    this->name2 = "l-l";
    this->positionX = COLS / 2 - 2;
    this->positionY = LINES - 8;
    Weapon  *weap = new Weapon(3, -1);
    this->weap = weap;
    this->health = 5;
}

PlayerShip::PlayerShip(const PlayerShip &p) : IShip(p) { (void) p; }
PlayerShip &PlayerShip::operator=(const PlayerShip &p) { (void) p; return *this; }

PlayerShip::~PlayerShip() { delete this->weap; }

int     PlayerShip::getPositionX(void) { return this->positionX; }
int     PlayerShip::getPositionY(void) { return this->positionY; }
int     PlayerShip::getHealth(void) { return this->health; }
time_t  PlayerShip::getLastDamage(void) { return this->lastDamage; }

void    PlayerShip::moveLeft(void) {
    this->positionX -= 3;
    if (this->positionX <= 1)
        this->positionX = 1;
}
void    PlayerShip::moveRight(void) {
    this->positionX += 3;
    if (this->positionX >= COLS - 4)
        this->positionX = COLS - 4;
}
void    PlayerShip::moveUp(void) {
    this->positionY -= 1;
    if (this->positionY <= 1)
        this->positionY = 1;
}
void    PlayerShip::moveDown(void) {
    this->positionY += 1;
    if (this->positionY >= LINES - 6)
        this->positionY = LINES - 6;
}

void    PlayerShip::getsDamage(int dmg) {
        this->health -= dmg;
    if (this->health <= 0)
        this->dies();
    lastDamage = time(nullptr);
    // XXX ajouter fonction scintillement vaisseau
}

void    PlayerShip::dies(void) 
{
    this->name1 = "MORTXX";
    // XXX Coder fonction explosion du vaisseau
    // XXX renvoyer vers game over
}

void    PlayerShip::printShip(WINDOW *win, const PlayerShip &p) 
{
    if (time(nullptr) - this->lastDamage < 2)
    {
        mvwprintw(win, p.positionY - 1, p.positionX, "*");
        mvwprintw(win, p.positionY - 1, p.positionX + 2, "*");
        mvwprintw(win, p.positionY - 1, p.positionX + 3, "*");
        mvwprintw(win, p.positionY, p.positionX + 3, "*");
        mvwprintw(win, p.positionY + 1, p.positionX + 3, "*");
        mvwprintw(win, p.positionY + 2, p.positionX + 3, "*");
        mvwprintw(win, p.positionY + 2, p.positionX + 2, "*");
        mvwprintw(win, p.positionY + 2, p.positionX, "*");
        mvwprintw(win, p.positionY + 2, p.positionX - 1, "*");
        mvwprintw(win, p.positionY + 1, p.positionX - 1, "*");
        mvwprintw(win, p.positionY, p.positionX - 1, "*");
        mvwprintw(win, p.positionY - 1, p.positionX - 1, "*");
    }

    mvwprintw(win, p.positionY, p.positionX, "%s", this->name1.c_str());
    mvwprintw(win, p.positionY + 1, p.positionX, "%s", this->name2.c_str());
}

// Can shoot only when not affected by damage
int     PlayerShip::shootsMissile(void)
{
    if (time(nullptr) - this->lastDamage < 2 || time(nullptr) - this->lastShot < 2 || weap->getAmmo() == 0)
        return 0;
    this->weap->shoots();
    this->lastShot = time(nullptr);
    return weap->getDamage();
}

