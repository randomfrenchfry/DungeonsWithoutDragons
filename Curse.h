#ifndef CURSE_H
#define CURSE_H
#include "Modifier.h"
using namespace std;

class Curse : Modifier{
public:
  void apply(int&);

};

void Curse::apply(int& state){
  state -= getEffect();
}

#endif
