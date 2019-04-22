#ifndef DAMAGE_H
#def DAMAGE_H
#include "TypeAdv.h"

class Damage{
public:
  Damage();
  Damage(int, TypeAdv*);
  int getDamage();
  void setDamage(int);
  TypeAdv& getAdvanteges();
  void addAdvantage(TypeAdv);
  bool removeAdvantage(TypeAdv);
  Damage operator+(Damage);
  Damage operator+(int);
  Damage operator+(TypeAdv);

private:
  int damage;
  TypeAdv* typeAdvanteges;

};

#endif
