#include "Weapon.h"

weapon::weapon() {
    wItem = "";
    wDamage = 0;
}
weapon::weapon(string i, int d) {
    wItem = i;
    wDamage = d;
}

string weapon::getItem() {
    return wItem;
}

int weapon::getDMG() {
    return wDamage;
}