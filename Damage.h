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
  Damage operator+(TypeAdv*);

private:
  int damage;
  TypeAdv* typeAdvantages;

};

Damage::Damage(){
  damage = 0;
  typeAdvantages = nullptr;
}
Damage::Damage(int dam, TypeAdv* typeAdvantage){
  damage = dam;
  typeAdvantages = typeAdvantage;
}

int Damage::getDamage(){
  return damage;
}
void Damage::setDamage(int dam){
  damage = dam;
}

TypeAdv& Damage::getAdvantages(){
  return typeAdvantages;
}

void Damage::addAdvantage(TypeAdv typeadvantage){

}
bool Damage::removeAdvantage(TypeAdv typeadvantage){

}
Damage Damage::operator+(Damage dam){
  int numOfAdvantages = typeAdvantages.length() + dam.getAdvantages.length();
  TypeAdv* newTypeAdvantages[numOfAdvantages];
  for(int i = 0; i < typeAdvantages.length(); i++){
    newTypeAdvantages[i] = typeAdvantages[i];
  }
  for(int i = 0; i < dam.getAdvantages.length(); i++){
    newTypeAdvantages[typeAdvantages.length() + i] = dam.getAdvantages[i];
  }
  Damage tempDamage(damage + dam.getDamage, newTypeAdvantages);
  return tempDamage;
}

Damage Damage::operator+(int dam){
  Damage tempDamage(damage + dam, typeAdvantages);
  return tempDamage;
}

Damage Damage::operator+(TypeAdv* advantages){
  int numOfAdvantages = typeAdvantages.length() + advantages.length();
  TypeAdv* newTypeAdvantages[numOfAdvantages];
  for(int i = 0; i < typeAdvantages.length(); i++){
    newTypeAdvantages[i] = typeAdvantages[i];
  }
  for(int i = 0; i < advantages.length(); i++){
    newTypeAdvantages[typeAdvantages.length() + i] = advantages[i];
  }
  Damage tempDamage(damage, newTypeAdvantages);
  return tempDamage;
}


#endif
