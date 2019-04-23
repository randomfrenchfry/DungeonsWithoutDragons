#ifndef CHARACTER_H
#define CHARACTER_H
#include "Weapon.h"
#include "State.h"
#include "Modifiers.h"

class Character{

public:
  Character(); //done
  Character(int, int, Damage); //Health, maxHealth, Damage //done
  void takeDamage(Damage);//done
  void heal(int);//done
  void upkeep();//applies all modifiers and calls their upkeeps, then removes expired modifiers
  Damage attack();// calculates the characters damage, waepon + currState
  Weapon getWeapon(); //done
  State getState();  //done
  void setWeapon(Weapon); //done
  void setState(State);//done
  void addModifier(Modifier);
  Modifier getModifier();

private:
  State currState;
  Weapon weapon;
  Modifier* modifiers;
};

Character::Character(){
  Damage tempDamage(0, nullptr);
  State tempState(100, 100, tempDamage);
  setState(tempState);
}
Character::Character(int baseHealth, int maxHealth, Damage dam){
  State tempState(baseHealth, maxHealth, dam);
  setState(tempState);
}
void Character::heal(int healAmount){
  currState.heal(healAmount);
}

void Character::takeDamage(Damage dam){
  
  currState.hurt(dam.getDamage());
}


void Character::setWeapon(Weapon other){
  weapon = other;
}
void Character::setState(State other){
  currState = other;
}
Weapon Character::getWeapon(){
  return weapon;
}
State Character::getState(){
  return currState;
}

#endif
