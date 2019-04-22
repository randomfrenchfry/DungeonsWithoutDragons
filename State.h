#ifndef STATE_H
#def STATE_H
#include "Damage.h"

class State{
public:
  State();
  State(int, int, Damage); // base health, maxhealth, Damage
private:
  int baseHealth;
  int healthMod;
  int maxHealth;
  Damage damage;
};

#endif
