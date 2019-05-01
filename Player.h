#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"
#include <cstdlib>
#include <ctime>
using namespace std;

class Player : public Character{
private:
  int experience;
  int level;
  bool hasKey;
  void levelup();
  string name;

public:
  Player();
  string getName();
  void setName(string);
  Player(int, int, Damage, Weapon, string);//health, max, dam, waepon, name
  void addExperience(int);
  int getExperience();
  void upkeep(); //same shit as parent but calls levelup
  void print();


};

void Player::setName(string nam){
  name = nam;
}

Player::Player() : Character(){
  experience = 0;
  level = 0;
  hasKey = false;
  name = "Stevie";
}

Player::Player(int baseHealth, int maxHealth, Damage dam, Weapon weap, string playerName) : Character(baseHealth, maxHealth, dam, weap){
  experience = 0;
  level = 0;
  hasKey = false;
  name = playerName;
}

string Player::getName(){
  return name;
}

void Player::addExperience(int xp){
  experience += xp;
}

int Player::getExperience(){
  return experience;
}

void Player::upkeep(){
  Character::upkeep();
  if(getState().getBaseHealth()<=0){
    throw runtime_error("You Have Died!");
  }
  while(experience >= 5 + level * 10){
    level++;
    levelup();
  }
  if(hasKey){
    throw runtime_error("You Found The Key! You escape!");
  }
}

void Player::levelup(){
  //cout << "Leveling up" <<endl;
  srand(time(nullptr));
  int tmp = 1 + rand() % 5;
  if(tmp == 1){
    //cout << tmp << "HAVEKEY";
    hasKey = true;
  }
}

void Player::print(){
  cout << name << ":" << endl;
  cout << "Level: " << level << " Exp: " << experience << endl;
  Character::print();
}

#endif
