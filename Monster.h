#ifndef MONSTER_H
#define MONSTER_H
#include <string>
using namespace std;

class Monster : public Character{
public:
  Monster();
  Monster(int, int, Damage, Weapon, string);//health, max, dam, weap, name
  Monster(const Monster&);
  void setName(string);
  string getName() const;
  void print();

private:
  string name;

};

Monster::Monster() : Character(){
  name = "Carl";
}

Monster::Monster(int bH, int mH, Damage dam, Weapon we, string nam) : Character(bH, mH, dam, we){
  name = nam;
}

Monster::Monster(const Monster& other) : Character(other){
  name = other.getName();
}

void Monster::setName(string nam){
  name = nam;
}

string Monster::getName() const{
  return name;
}

void Monster::print(){
  cout << name << ": " << endl;
  Character::print();
}

#endif
