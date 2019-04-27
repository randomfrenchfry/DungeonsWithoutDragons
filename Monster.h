#ifndef MONSTER_H
#define MONSTER_H
#include <string>
using namespace std;

class Monster : Character{
public:
  Monster();
  Monster(int, int, Damage, Weapon, string);
  void setName(string);
  string getName();

private:
  string name;

};

Monster::Mosnter() : Character(){
  name = "Carl";
}

Monster::Monster(int bH, int mH, Damage dam, Weapon we, string nam) : Character(bH, mH, dam, we){
  name = nam;
}

void Monster::setName(string nam){
  name = nam;
}

string Monster::getName(){
  return name;
}

#endif
