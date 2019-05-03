#ifndef STATE_H
#define STATE_H
#include "Damage.h"
using namespace std;

class State{
public:
  State();
  State(int, int, Damage); // base health, maxhealth, Damage
  State operator=(State);
  void setBaseHealth(int);
  int getBaseHealth() const;
  void setMaxHealth(int);
  int getMaxHealth() const;
  int* getHealthMod();
  int getHealthMod2() const;
  void heal(int);
  void hurt(int);
  void weaken(int);
  void strengthen(int);
  void setDamage(Damage);
  Damage getDamage() const;
  int getDamageMod() const;
  void upkeep(); // apply healthMod to base Health, dont exceed
  void print();

private:
  int baseHealth;
  int healthMod;
  int maxHealth;
  Damage damage;
  int damageMod;
};

State::State(){
  baseHealth = 0;
  healthMod = 0;
  maxHealth = 0;
  Damage tmp;
  damage = tmp;
  damageMod = 0;
}

State::State(int bH, int mH, Damage dam){
  baseHealth = bH;
  healthMod = 0;
  maxHealth = mH;
  damage = dam;
  damageMod = 0;
}

State State::operator=(State other){
  this->baseHealth = other.getBaseHealth();
  this->maxHealth = other.getMaxHealth();
  this->healthMod = other.getHealthMod2();
  this->damage = other.getDamage();
  this->damageMod = other.getDamageMod();
  return *this;
}

int* State::getHealthMod(){
  return &healthMod;
}

int State::getHealthMod2() const{
  return healthMod;
}

int State::getDamageMod() const{
  return damageMod;
}

void State::setBaseHealth(int bH){
  baseHealth = bH;
}

int State::getBaseHealth()const{
  return baseHealth;
}

void State::setMaxHealth(int mH){
  maxHealth = mH;
}

int State::getMaxHealth()const{
  return maxHealth;
}

void State::heal(int he){
  baseHealth += he;
  if(baseHealth > maxHealth){
    baseHealth = maxHealth;
  }
}

void State::hurt(int hurt){
  baseHealth -= hurt;
}

void State::weaken(int we){
  damageMod -= we;
}

void State::strengthen(int str){
  damageMod += str;
}

void State::setDamage(Damage dam){
  damage = dam;
}

Damage State::getDamage()const{
  return damage;
}

void State::upkeep(){
  baseHealth += healthMod;
  if(baseHealth > maxHealth){
    baseHealth = maxHealth;
  }
}

void State::print(){
  cout << "Health: " << baseHealth << " Max Health: " << maxHealth << endl;
  cout << "Base Damage : " << damage.getDamage() << endl;
}

#endif
