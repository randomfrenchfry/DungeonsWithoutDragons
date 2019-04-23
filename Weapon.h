#ifndef WEAPON_H
#define WEAPON_H
#include "TypeAdv.h"
#include "Damage.h"

class Weapon{
private:
  int damage;
  TypeAdv typeadvantage;

public:
  Weapon();
  Weapon(int, TypeAdv);
  void setDamage(int);
  int getDamage();
  void setTypeAdv(TypeAdv);
  TypeAdv getTypeAdv();
  Damage attack();

};

#endif
