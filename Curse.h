#ifndef CURSE_H
#define CURSE_H
#include "Modifier.h"

class Curse : Modifier{

};

void Modifier::apply(State& state){
  state.weaken(fetEffect());
}

#endif
