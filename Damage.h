#ifndef DAMAGE_H
#define DAMAGE_H
#include "Modifier.h"
using namespace std;

class Damage{
public:
  Damage();
  Damage(int);
  Damage(int, Modifier*, int);
  int getDamage();
  void setDamage(int);
  Modifier* getAdvantages();
  void addAdvantage(Modifier);
  bool removeAdvantage(Modifier);
  int getNumMods();
  Damage operator+(Damage);
  Damage operator+(int);
  //Damage operator+(Modifier*);

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

Damage::Damage(int dam){
  damage = dam;
  typeAdvantages = nullptr;
  numMods = 0;
}

Damage::Damage(int dam, Modifier* typeAdvantage, int num){
  damage = dam;
  typeAdvantages = typeAdvantage; // NEEDS TO BE A DEEP COPY
  numMods = num;
}

int Damage::getDamage(){
  return damage;
}
void Damage::setDamage(int dam){
  damage = dam;
}

Modifier* Damage::getAdvantages(){
  return typeAdvantages;
}

int Damage::getNumMods(){
  return numMods;
}

void Damage::addAdvantage(Modifier typeadvantage){
  if(typeAdvantages == nullptr){
    typeAdvantages = new Modifier[1];
    typeAdvantages[0] = typeadvantage;
  }else{
    Modifier* tmp = new Modifier[numMods+1];
    for(int i=0; i<numMods-1; i++){
      tmp[i] = typeAdvantages[i];
    }
    tmp[numMods] = typeadvantage;
    delete[] typeAdvantages;
    typeAdvantages = tmp;
  }
  numMods++;
}

bool Damage::removeAdvantage(Modifier typeadv){
  int pos = -1;
  for(int i=0; i<numMods;i++){
    if(typeadv.getType() == typeAdvantages[i].getType()){
      pos = i;
    }
  }
  if(pos == -1){
    return false;
  }
  Modifier* tmp = new Modifier[numMods-1];
  int cnt = 0;
  for(int i=0; i<numMods;i++){
    if(pos != i){
      tmp[cnt] = typeAdvantages[i];
      cnt++;
    }
  }
  typeAdvantages = tmp;
  return true;
}
Damage Damage::operator+(Damage dam){
  int numOfAdvantages = numMods + dam.getNumMods();
  Modifier newTypeAdvantages[numOfAdvantages];
  for(int i = 0; i < numMods; i++){
    newTypeAdvantages[i] = typeAdvantages[i];
  }
  for(int i = 0; i < dam.getNumMods(); i++){
    newTypeAdvantages[numMods + i] = dam.getAdvantages()[i];
  }
  Damage tempDamage(damage + dam.getDamage(), newTypeAdvantages, numOfAdvantages);
  return tempDamage;
}

Damage Damage::operator+(int dam){
  Damage tempDamage(damage + dam, typeAdvantages, numMods);
  return tempDamage;
}
/*
Damage Damage::operator+(Modifier* advantages, int num){
  int numOfAdvantages = numMods + num;
  Modifier* newTypeAdvantages[numOfAdvantages];
  for(int i = 0; i < numMods; i++){
    newTypeAdvantages[i] = typeAdvantages[i];
  }
  for(int i = 0; i < num; i++){
    newTypeAdvantages[numMods + i] = advantages[i];
  }
  Damage tempDamage(damage, newTypeAdvantages, numOfAdvantages);
  return tempDamage;
}
*/

#endif
