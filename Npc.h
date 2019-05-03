#ifndef NPC_H
#define NPC_H
#include "Character.h"
#include <string>
using namespace std;

class Npc : public Character{
public:
  Npc();
  Npc(int, int, Damage, Weapon, string);
  Npc operator=(Npc);
  Npc(const Npc&);
  //Npc(const Npc&&);
  void setName(string);
  string getName() const;
  void print();

private:
  string name;

};

Npc::Npc() : Character(){
  name = "Gustav";
}

Npc::Npc(int bH, int mH, Damage dam, Weapon we, string nam) : Character(bH, mH, dam, we){
  name = nam;
}

Npc Npc::operator=(Npc other){
  Character::operator=(other);
  this->name = other.getName();
  return *this;
}

Npc::Npc(const Npc& other) : Character(other){
  this->name = other.getName();
}

//Npc::Npc(const Npc&& other) : Character(other){
//  this->name = other.name;
//}

void Npc::setName(string nam){
  name = nam;
}

string Npc::getName() const{
  return name;
}

void Npc::print(){
  cout << name << ": " << endl;
  Character::print();
}

#endif
