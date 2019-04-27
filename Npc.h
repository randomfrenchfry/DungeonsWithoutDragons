#ifndef NPC_H
#define NPC_H
#include "Character.h"

class Npc : Character{
public:
  Npc();
  Npc();
  void setName();
  string getName();

private:
  string name;

};

Npc::Npc() : Character(){
  name = "Carlos";
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

#endif
