#ifndef CHARACTER_H
#define CHARACTER_H
#include "Weapon.h"
#include "State.h"
#include "Modifiers.h"

class Character{

public:
  Character();
  Character(int, int, Damage, Weapon); //Health, maxHealth, Damage, Weapon
  void takeDamage(Damage);
  void heal(int);
  void upkeep();//applies all modifiers and calls their upkeeps, then removes expired modifiers //finish
  Damage attack();// calculates the characters damage, waepon + currState
  Weapon getWeapon();
  State getState();
  void setWeapon(Weapon);
  void setState(State);
  void addModifier(Modifier); //finish
  Modifier getModifier(); //finish

private:
  State currState;
  Weapon weapon;
  Modifier* modifiers;//TypeAdv in here should have effect = 0 when listin a characters type
};

Character::Character(){
  Damage tempDamage(0, nullptr);
  State tempState(100, 100, tempDamage);
  setState(tempState);
  Weapon tempWeapon();
  modifiers = nulptr;
}
Character::Character(int baseHealth, int maxHealth, Damage dam, Weapon weap){
  State tempState(baseHealth, maxHealth, dam);
  setState(tempState);
  weapon = weap;
  modifiers = nulptr;
}
void Character::heal(int healAmount){
  currState.heal(healAmount);
}

void Character::takeDamage(Damage dam){
  int tmpDam = dam.getDamage();
  TypeAdv* arr = dam.getTypeAdv();
  //check for typeAdvantages
  int damMod = 0;
  for(int i=0;i<arr.length(); i++){
    for(int j=0; j<modifiers.length(); j++){
      string className = typeid(modifiers[j]).name();
      if(className == "TypeAdv"){//check if modifiers[j] is a TypeAdv and if it is the same type as arr[i]
        if(arr[i].getType() == modifiers[j].getType()){
          damMod += arr[i].getEffect();
          damMod += modifiers[j].getEffect();
        }
      }
    }
  }
  currState.hurt(dam.getDamage());
}
Damage Character::attack(){
  Damage total_damage = weapon.attack() + currState.getDamage();
  return total_damage;
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
void Character::addModifier(Modifier other){
  if(modifiers == nullptr){
    modifiers = new Modifiers[1];
    modifiers[0] = other;
  }else{
    Modifier* tmp = new Modifier[modifiers.length()+1];
    for(int i=0; i<tmp.length()-1){
      tmp[i] = modifiers[i];
    }
    tmp[modifiers.length()] = other;
    delete[] modifiers;
    modifiers = tmp;
    delete tmp;
  }
}

void Character::getModifier(){
  //finish
}

void Character::upkeep(){
  //finish
}

#endif
