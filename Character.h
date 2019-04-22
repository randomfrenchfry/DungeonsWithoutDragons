#ifndef CHARACTER_H
#def    CHARACTER_H
#include "Weapon.h"
#include "State.h"

class Character{

public:
  Character();
  Character(int, int);
  void takeDamage(int);
  void heal(int);

private:
  State currState;
  Weapon weapon;




};



#endif
