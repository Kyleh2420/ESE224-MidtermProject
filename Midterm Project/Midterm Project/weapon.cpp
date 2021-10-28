#include "Weapon.h"

weapon::weapon() {
    wItem = "";
    wDamage = 0;
    wCost = 0;
}
weapon::weapon(string i, int d, int c) {
    wItem = i;
    wDamage = d;
    wCost = c;
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