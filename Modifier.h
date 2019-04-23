#ifndef MODIFIER_H
#define MODIFIER_H
#include "State.h"

class Modifier{
public:
  Modifier();
  Modifier(int, int);//effect, duration
  int getEffect();
  void setEffect(int);
  int getDuration();
  void setDuration(int);
  bool upkeep(); //called by the upkeep func of other classes, decrements duration by one; returns true when mod should be deleted
  virtual void apply(State&) = 0;

private:
  int effect;
  int duration;

};

Modifier::Modifier(){
  effect = 0;
  duration = -1;
}

Modifier::Modifier(int eff, int dur){
  effect = eff;
  duration = dur;
}

int Modifier::getEffect(){
  return effect;
}

void Modifier::setEffect(int eff){
  effect = eff;
}

int Modifier::getDuration(){
  return duration;
}

void Modifier::setDuration(int dur){
  duration = dur;
}

bool Modifier::upkeep(){
  duration -= 1;
  if(duration == 0){
    return true;
  }
  return false;
}

#endif
