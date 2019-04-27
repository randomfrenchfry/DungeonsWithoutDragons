#ifndef DAMAGE_H
#define DAMAGE_H
#include "Modifier.h"
using namespace std;

class Damage{
public:
  Damage();
  Damage(int, Modifier*);
  int getDamage();
  void setDamage(int);
  Modifier& getAdvantages();
  void addAdvantage(Modifier);
  bool removeAdvantage(Modifier);
  Damage operator+(Damage);
  Damage operator+(int);
  Damage operator+(Modifier*);

private:
  int damage;
  Modifier* typeAdvantages;
  int numMods;

};

Damage::Damage(){
  damage = 0;
  typeAdvantages = nullptr;
  numMods = 0;
}
Damage::Damage(int dam, Modifier* typeAdvantage){
  damage = dam;
  *typeAdvantages = *typeAdvantage; // NEEDS TO BE A DEEP COPY
  numMods = 0;
}

int Damage::getDamage(){
  return damage;
}
void Damage::setDamage(int dam){
  damage = dam;
}

Modifier& Damage::getAdvantages(){
  return *typeAdvantages;
}

void Damage::addAdvantage(Modifier typeadvantage){
  if(typeAdvantages == nullptr){
    typeAdvantages = new Modifier[1];
    typeAdvantages[0] = typeadvantage;
  }else{
    Modifier* tmp = new Modifier[typeAdvantages->length()+1];
    for(int i=0; i<tmp->length()-1; i++){
      tmp[i] = typeAdvantages[i];
    }
    tmp[typeAdvantages->length()] = typeadvantage;
    delete[] typeAdvantages;
    typeAdvantages = tmp;
  }
  numMods++;
}

bool Damage::removeAdvantage(Modifier typeadv){
  for(int i=0; i<typeAdvantages->length();i++){
    if(typeadv.getType() == typeAdvantages[i].getType()){
      typeAdvantages[i] = null;
      return true;
  }
  return false;
}
Damage Damage::operator+(Damage dam){
  int numOfAdvantages = typeAdvantages.length() + dam.getAdvantages.length();
  Modifier* newTypeAdvantages[numOfAdvantages];
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

Damage Damage::operator+(Modifier* advantages){
  int numOfAdvantages = typeAdvantages.length() + advantages.length();
  Modifier* newTypeAdvantages[numOfAdvantages];
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
