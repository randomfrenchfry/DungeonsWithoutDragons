#ifndef BOON_H
#define BOON_H
#include "Modifier.h"
using namespace std;


class Boon : public Modifier{
public:
  Boon();
  Boon(int, int);
  void apply(int*);

};

Boon::Boon() : Modifier(){

}

Boon::Boon(int eff, int dur) : Modifier(eff, dur){

}

void Boon::apply(int* state){
  *state += getEffect();
}

#endif
