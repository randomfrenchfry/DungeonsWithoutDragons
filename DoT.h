#ifndef DOT_H
#define DOT_H
#include "Modifier.h"
using namespace std;

class DoT: Modifier{
public:
  void apply(int&);
};

void DoT::apply(int& state){
  state -= getEffect();
}

#endif
