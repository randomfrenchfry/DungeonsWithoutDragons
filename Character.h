#ifndef CHARACTER_H
#define CHARACTER_H
#include "Weapon.h"
#include "State.h"
#include "Modifier.h"
#include <vector>
using namespace std;


class Character{

public:
  Character();
  Character(int, int, Damage, Weapon); //Health, maxHealth, Damage, Weapon
  Character(const Character& other);
  Character operator=(Character);
  void takeDamage(Damage);
  void heal(int);
  void upkeep();//applies all modifiers and calls their upkeeps, then removes expired modifiers
  Damage attack();// calculates the characters damage, waepon + currState
  Weapon getWeapon() const;
  State getState() const;
  //int getNumMods();
  void setWeapon(Weapon);
  void setState(State);
  void addModifier(Modifier); //finish
  vector<Modifier> getModifiers() const; //finish
  void print();

private:
  State currState;// all clas advantages should be added to state Damage object
  Weapon weapon;
  vector<Modifier> modifiers;//TypeAdv in here should have effect = 0 when listin a characters type
  //int numMods;
};

Character::Character(){
  Damage tempDamage(0);
  State tempState(100, 100, tempDamage);
  setState(tempState);
  Weapon tempWeapon();
  //numMods = 0;
}
Character::Character(int baseHealth, int maxHealth, Damage dam, Weapon weap){
  State tempState(baseHealth, maxHealth, dam);
  setState(tempState);
  setWeapon(weap);
  //numMods = 0;
}

Character::Character(const Character& other){
  setState(other.getState());
  setWeapon(other.getWeapon());
  //numMods = other.getNumMods();
  for(int i=0; i<other.getModifiers().size(); i++){
    modifiers.push_back(other.getModifiers()[i]);
  }
}

Character Character::operator=(Character other){
  setState(other.getState());
  setWeapon(other.getWeapon());
  modifiers.clear();
  for(int i=0; i<other.getModifiers().size(); i++){
    modifiers.push_back(other.getModifiers()[i]);
  }
  return *this;
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
  for(int i=0; i<modifiers.size();i++){
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
Weapon Character::getWeapon() const{
  return weapon;
}
State Character::getState() const{
  return currState;
}

//int Character::getNumMods(){
//  return numMods;
//}

void Character::addModifier(Modifier other){
  /*
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
  */
  modifiers.push_back(other);
}

vector<Modifier> Character::getModifiers() const{
  //finish -nah
  //cout << "DEPRECIATED";
  return modifiers;
}

void Character::upkeep(){
  for(int i=0; i<modifiers.size();i++){
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
