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
