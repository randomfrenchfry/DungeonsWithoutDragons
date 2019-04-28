#ifndef DOT_H
#define DOT_H
#include "Modifier.h"
using namespace std;

class DoT: public Modifier{
public:
  DoT();
  DoT(int, int);
  void apply(int*);
};

DoT::DoT() : Modifier(){

}

DoT::DoT(int eff, int dur) : Modifier(eff, dur){

}

void DoT::apply(int* state){
  *state -= getEffect();
}

#endif
