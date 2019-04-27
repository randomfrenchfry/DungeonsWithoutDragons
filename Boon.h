#ifndef BOON_H
#define BOON_H
#include "Modifier.h"
using namespace std;


class Boon : Modifier{
public:
  void apply(int&);

};

void Boon::apply(int& state){
  state += getEffect();
}

#endif
