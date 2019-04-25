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

Weapon::Weapon(){
  damage = 0;
  typeadvantage = NULL;
}

Weapon::Weapon(int dam, TypeAdv weaponType){
  damage = dam;
  typeadvantage = weaponType;
}

void Weapon::setDamage(int dam){
  damage = dam;
}

int Weapon::getDamage(){
  return damage;
}

void Weapon::setTypeAdv(TypeAdv weaponType){
  typeadvantage = weaponType;
}

TypeAdv Weapon::getTypeAdv(){
  return typeadvantage;
}

Damage Weapon::attack(){
  Damage tempDamage(damage, typeadvantage);
  return tempDamage;
}

#endif
