#ifndef CHARACTER_H
#def    CHARACTER_H
#include "Weapon.h"
#include "State.h"
#include "Modifiers.h"

class Character{

public:
  Character();
  Character(int, int);
  void takeDamage(int);
  void heal(int);
  void upkeep();
  Damage attack();

private:
  State currState;
  Weapon weapon;
  Modifier* modifiers;




};



#endif
