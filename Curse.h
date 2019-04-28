#ifndef CURSE_H
#define CURSE_H
#include "Modifier.h"
using namespace std;

class Curse : public Modifier{
public:
  Curse();
  Curse(int , int);
  void apply(int*);

};

Curse::Curse() : Modifier(){

}

Curse::Curse(int eff, int dur) : Modifier(eff, dur){

}

void Curse::apply(int* state){
  *state -= getEffect();
}

#endif
