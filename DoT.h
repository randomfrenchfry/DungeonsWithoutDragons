#ifndef DOT_H
#define DOT_H
#include "Modifier.h"

class DoT: Modifier{

};

void Dot::apply(State& state){
  state.hurt(this->getEffect());
}

#endif
