#include "enemy.h"

enemy::enemy() {
    name = "";
    maxHealth = 0;
    healthPoints = 0;
    attackDamage = 0;
    level = 0;
}

enemy::enemy(string n, int max, int hp, int ad, int lvl) {
    name = n;
    maxHealth = max;
    healthPoints = hp;
    attackDamage = ad;
    level = lvl;
}

//Getters!
string enemy::getName() {
    return name;
}
int enemy::getMaxHP() {
    return maxHealth;
}
int enemy::getHP() {
    return healthPoints;
}
int enemy::getDMG() {
    return attackDamage;
}

//Setters!
void enemy::setName(string input) {
    name = input;
}
void enemy::setMaxHP(int input) {
    maxHealth = input;
}
void enemy::setHP(int input) {
    healthPoints = input;
}
void enemy::setDMG(int input) {
    attackDamage = input;
}
void enemy::setLvl(int input) {
    level = input;
}

//Modifiers
void enemy::modHealth(int input) {
    healthPoints += input;
    if (healthPoints > maxHealth)
        healthPoints = maxHealth;
}

void enemy::modDamage(int input) {
    attackDamage += input;
    if (attackDamage < 0) {
        attackDamage = 0;
    }
}

ostream& operator << (ostream& os, const enemy& e) {
    os << "Name: " << e.name << "Max Health: " << e.maxHealth 
    << "HP: " <<  e.healthPoints << "Damage: " << e.attackDamage << "Level: " <<  e.level;
    return os;
}