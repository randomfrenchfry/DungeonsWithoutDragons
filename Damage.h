#ifndef DAMAGE_H
#define DAMAGE_H
#include "TypeAdv.h"

class Damage{
public:
  Damage();
  Damage(int, TypeAdv*);
  int getDamage();
  void setDamage(int);
  TypeAdv& getAdvantages();
  void addAdvantage(TypeAdv);
  bool removeAdvantage(TypeAdv);
  Damage operator+(Damage);
  Damage operator+(int);
  Damage operator+(TypeAdv);

private:
  int damage;
  TypeAdv* typeAdvantages;

};

#endif
