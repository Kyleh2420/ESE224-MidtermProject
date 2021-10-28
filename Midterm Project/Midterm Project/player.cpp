#include "player.h"

//Constructors
player::player() {
    name = "";
    maxHealth = 10;
    healthPoints = 10;
    attackDamage = 2;
    weaponName = "Hand";
    balance = 0;
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
int player::getBal() {
    return balance;
}
string player::getWeapon() {
    return weaponName;
}


//Setters!
void player::setName(string in) {
    name = in;
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
void player::setBal(int input) {
    balance = input;
}
void player::setWeapon(string in) {
    weaponName = in;
}


//Modifiers
//The input must be a signed number, either adding hp or removing hp.
//You cannot add more HP than the maxHealth
void player::modHealth(int input) {
    healthPoints += input;
    if (healthPoints > maxHealth)
        healthPoints = maxHealth;
    if (healthPoints <= 0)
        cout << "We're sorry, you have died!" << endl;
}

//Damage Modifier: Input is a signed interger. Attack damage cannot be lower than 0
void player::modDamage(int input) {
    attackDamage += input;
    if (attackDamage < 0)
        attackDamage = 0;
}

//Modifies Player's money. Input is signed, Balance cannot be lower than 0.
void player::modBal(int input) {
    balance += input;
    if (balance < 0)
        balance = 0;
}

ostream& operator <<(ostream& os, const player& p) {
    os << "\nName: " << p.name << "\nMax Health: " << p.maxHealth 
    << "\nHP: " <<  p.healthPoints << "\nWeapon: " << p.weaponName
    << "\nDamage: " << p.attackDamage <<"\nBalance: " << p.balance
    << endl;
    return os;
}