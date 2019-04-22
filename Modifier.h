#ifndef MODIFIER_H
#def MODIFIER_H
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
  virtual void apply(State) = 0;
  
private:
  int effect;
  int duration;

};

#endif
