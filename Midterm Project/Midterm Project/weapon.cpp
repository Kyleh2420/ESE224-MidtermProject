#include "Weapon.h"

weapon::weapon() {
    wItem = "";
    wDamage = 0;
    wCost = 0;
    wMaxHP = 0;
    wHP = 0;
}
weapon::weapon(string i, int d, int c, int m, int h) {
    wItem = i;
    wDamage = d;
    wCost = c;
    wMaxHP = m;
    wHP = h;
}

//Getters
string weapon::getItem() {
    return wItem;
}

int weapon::getDMG() {
    return wDamage;
}

int weapon::getCost() {
    return wCost;
}
int weapon::getMaxHP() {
    return wMaxHP;
}
int weapon::getHP() {
    return wHP;
}

//Setters
void weapon::setItem(string in) {
    wItem = in;
}
void weapon::setDMG(int i) {
    wDamage = i;
}
void weapon::setCost(int i) {
    wCost = i;
}
void weapon::setMaxHP(int i) {
    wMaxHP = i;
}
void weapon::setHP(int i) {
    wHP = i;
}