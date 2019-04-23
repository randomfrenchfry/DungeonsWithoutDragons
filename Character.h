#ifndef CHARACTER_H
#define    CHARACTER_H
#include "Weapon.h"
#include "State.h"
#include "Modifiers.h"

class Character{

public:
  Character();
  Character(int, int);
  void takeDamage(int);
  void heal(int);
  void upkeep();//applies all modifiers and calls their upkeeps, then removes expired modifiers
  Damage attack();// calculates the characters damage, waepon + currState
  void setWeapon(Weapon);
  Weapon getWeapon();
  void setState(State);
  State getState();
  void addModifier(Modifier);
  Modifier getModifier();

private:
  State currState;
  Weapon weapon;
  Modifier* modifiers;




};



#endif
