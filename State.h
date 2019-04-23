#ifndef STATE_H
#define STATE_H
#include "Damage.h"

class State{
public:
  State();
  State(int, int, Damage); // base health, maxhealth, Damage
  void setBaseHealth(int);
  int getBaseHealth();
  void setMaxHealth(int);
  int getMaxHealth();
  void heal(int);
  void hurt(int);
  void setDamage(Damage);
  Damage getDamage();
  void upkeep(); // apply healthMod to base Health    

private:
  int baseHealth;
  int healthMod;
  int maxHealth;
  Damage damage;
};

#endif
