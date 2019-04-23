#ifndef BOON_H
#define BOON_H
#include "Modifier.h"

class Boon : Modifier{

};

void Boon::apply(State& state){
  state.heal(this->getEffect());
}

#endif
