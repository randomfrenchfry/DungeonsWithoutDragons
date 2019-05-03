#ifndef WEAPON_H
#define WEAPON_H
#include "TypeAdv.h"
#include "Damage.h"
using namespace std;

class Weapon{
private:
  int damage;
  TypeAdv typeadvantage;

public:
  Weapon();
  Weapon(int, TypeAdv);
  Weapon operator=(Weapon);
  Weapon(const Weapon&);
  ~Weapon();
  void setDamage(int);
  int getDamage() const;
  void setTypeAdv(TypeAdv);
  TypeAdv getTypeAdv() const;
  Damage attack();
  void print();

};

Weapon::Weapon(){
  damage = 0;
  TypeAdv tmp;
  typeadvantage = tmp;
}

Weapon::Weapon(int dam, TypeAdv weaponType){
  damage = dam;
  typeadvantage = weaponType;
}

Weapon::Weapon(const Weapon& other){
  damage = other.getDamage();
  typeadvantage = other.getTypeAdv();
}

Weapon::~Weapon(){

}

Weapon Weapon::operator=(Weapon other){
  this->damage = other.getDamage();
  this-> typeadvantage = other.getTypeAdv();
}

void Weapon::setDamage(int dam){
  damage = dam;
}

int Weapon::getDamage() const{
  return damage;
}

void Weapon::setTypeAdv(TypeAdv weaponType){
  typeadvantage = weaponType;
}

TypeAdv Weapon::getTypeAdv() const{
  return typeadvantage;
}

Damage Weapon::attack(){
  Damage tempDamage(damage);
  tempDamage.addAdvantage(typeadvantage);
  return tempDamage;
}

void Weapon::print(){
  cout << "Weapon power: " << damage << endl;
}

#endif
