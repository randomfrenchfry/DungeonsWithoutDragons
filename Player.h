#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"

class Player : Character{
private:
  int experience;
  int level;
  void levelup();

public:
  void addExperience();
  int getExperience();
  void upkeep(); //same shit as parent but calls levelup


};

#endif
