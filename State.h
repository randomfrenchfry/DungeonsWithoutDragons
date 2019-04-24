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
  void weaken(int);
  void strengthen(int);
  void setDamage(Damage);
  Damage getDamage();
  void upkeep(); // apply healthMod to base Health, dont exceed

private:
  int baseHealth;
  int healthMod;
  int maxHealth;
  Damage damage;
  int damageMod;
};

#endif
