#include "player.h"

//Constructors
player::player() {
    name = "";
    maxHealth = 10;
    healthPoints = 10;
    attackDamage = 2;
}

//Getters
string player::getName() {
    return name;
}

int player::getMaxHP() {
    return maxHealth;
}

int player::getHP() {
    return healthPoints;
}

int player::getDMG() {
    return attackDamage;
}


//Setters!
void player::setName(istream& in) {
    in >> name;
}
void player::setMaxHP(int input) {
    maxHealth = input;
}

void player::setHP(int input) {
    healthPoints = input;
}
void player::setDMG(int input) {
    attackDamage = input;
}


//Modifiers
//The input must be a signed number, either adding hp or removing hp.
//You cannot add more HP than the maxHealth
void player::modHealth(int input) {
    healthPoints += input;
    if (healthPoints > maxHealth)
        healthPoints = maxHealth;
}

//Damage Modifier: Input is a signed interger. Attack damage cannot be lower than 0
void player::modDamage(int input) {
    attackDamage += input;
    if (attackDamage < 0)
        attackDamage = 0;
}

ostream& operator <<(ostream& os, const player& p) {
    os << "Name: " << p.name << "Max Health: " << p.maxHealth 
    << "HP: " <<  p.healthPoints << "Damage: " << p.attackDamage;
    return os;
}