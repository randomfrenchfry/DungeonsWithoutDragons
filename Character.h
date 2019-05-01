#ifndef CHARACTER_H
#define CHARACTER_H
#include "Weapon.h"
#include "State.h"
#include "Modifier.h"
using namespace std;


class Character{

public:
  Character();
  Character(int, int, Damage, Weapon); //Health, maxHealth, Damage, Weapon
  void takeDamage(Damage);
  void heal(int);
  void upkeep();//applies all modifiers and calls their upkeeps, then removes expired modifiers
  Damage attack();// calculates the characters damage, waepon + currState
  Weapon getWeapon();
  State getState();
  int getNumMods();
  void setWeapon(Weapon);
  void setState(State);
  void addModifier(Modifier); //finish
  Modifier getModifier(); //finish
  void print();

private:
  State currState;// all clas advantages should be added to state Damage object
  Weapon weapon;
  Modifier* modifiers;//TypeAdv in here should have effect = 0 when listin a characters type
  int numMods;
};

Character::Character(){
  Damage tempDamage(0);
  State tempState(100, 100, tempDamage);
  setState(tempState);
  Weapon tempWeapon();
  modifiers = nullptr;
  numMods = 0;
}
Character::Character(int baseHealth, int maxHealth, Damage dam, Weapon weap){
  State tempState(baseHealth, maxHealth, dam);
  setState(tempState);
  weapon = weap;
  modifiers = nullptr;
  numMods = 0;
}
void Character::heal(int healAmount){
  currState.heal(healAmount);
}

void Character::takeDamage(Damage dam){
  /*
  int tmpDam = dam.getDamage();
  Modifier* arr = dam.getAdvantages();
  int tmpNum = dam.getNumMods();
  //check for typeAdvantages
  int damMod = 0;
  for(int i=0;i<tmpNum; i++){
    for(int j=0; j<numMods; j++){
      string className = typeid(modifiers[j]).name();
      if(className == "TypeAdv"){//check if modifiers[j] is a TypeAdv and if it is the same type as arr[i]
        if(arr[i].getType() == modifiers[j].getType()){
          damMod += arr[i].getEffect();
          damMod += modifiers[j].getEffect();
        }
      }
    }
  }
  */
  currState.hurt(dam.getDamage());
}
Damage Character::attack(){
  Damage total_damage = weapon.attack() + currState.getDamage();
  for(int i=0; i<numMods;i++){
    if(typeid(modifiers[i]).name() == "TypeAdv"){
      total_damage.addAdvantage(modifiers[i]);
    }
  }
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

int Character::getNumMods(){
  return numMods;
}

void Character::addModifier(Modifier other){
  if(modifiers == nullptr){
    modifiers = new Modifier[1];
    modifiers[0] = other;
    numMods++;
  }else{
    Modifier* tmp = new Modifier[numMods+1];
    for(int i=0; i<numMods; i++){
      tmp[i] = modifiers[i];
    }
    tmp[numMods] = other;
    delete[] modifiers;
    modifiers = tmp;
    numMods++;
  }
}

Modifier Character::getModifier(){
  //finish -nah
  cout << "DEPRECIATED";
}

void Character::upkeep(){
  for(int i=0; i<numMods;i++){
    if(typeid(modifiers[i]).name() == "Boon" || typeid(modifiers[i]).name() == "DoT"){
      modifiers[i].apply(currState.getHealthMod());
      if(modifiers[i].upkeep()){
        modifiers[i].setEffect(0);
      }
    }
  }
}

void Character::print(){
  currState.print();
  weapon.print();
}

#endif
