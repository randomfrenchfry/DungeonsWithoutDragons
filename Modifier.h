#ifndef MODIFIER_H
#def MODIFIER_H

class Modifier{
public:
  Modifier();
  Modifier(int, int);//effect, duration
  int getEffect();
  void setEffect(int);
  int getDuration();
  void setDuration(int);
  void upkeep(); //called by the upkeep func of other classes, decrements duration by one
private:
  int effect;
  int duration;

};

#endif
