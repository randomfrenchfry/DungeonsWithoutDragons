#ifndef STATE_H
#def STATE_H
#include "Damage.h"

class State{
public:
  State();
  State(int, int, Damage); // base health, maxhealth, Damage
  void setBaseHealth(int);
  int getBaseHealth();
  void setMaxHealth(int);
  int getMaxHealth();
  void setDamage(Damage);
  Damage getDamage(); 

private:
  int baseHealth;
  int healthMod;
  int maxHealth;
  Damage damage;
};

#endif
