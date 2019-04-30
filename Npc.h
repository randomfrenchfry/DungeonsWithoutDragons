#ifndef NPC_H
#define NPC_H
#include "Character.h"
#include <string>
using namespace std;

class Npc : public Character{
public:
  Npc();
  Npc(int, int, Damage, Weapon, string);
  void setName(string);
  string getName();
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

void Npc::setName(string nam){
  name = nam;
}

string Npc::getName(){
  return name;
}

void Npc::print(){
  cout << name << ": " << endl;
  Character::print();
}

#endif
