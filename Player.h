#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"
#include <cstdlib>
#include <ctime>

class Player : Character{
private:
  int experience;
  int level;
  bool hasKey;
  void levelup();

public:
  Player();
  void addExperience(int);
  int getExperience();
  void upkeep(); //same shit as parent but calls levelup


};

void Player::addExperience(int xp){
  experience += xp;
}

int Player::getExperience(){
  return experience;
}

void Player::upkeep() : upkeep(){
  if(experience >= level * 10){
    level++;
    levelup();
  }
}

void Player::levelup(){
  srand(time(nullptr));
  int tmp = 1 + rand() % 5;
  if(tmp == 1){
    hasKey = true;
  }
}

#endif
