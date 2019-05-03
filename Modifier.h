#ifndef MODIFIER_H
#define MODIFIER_H
#include <iostream>
#include <string>
using namespace std;

class Modifier{
public:
  Modifier();
  Modifier(int, int);//effect, duration
  Modifier(Modifier&);
  //~Modifier();
  Modifier(const Modifier&);
  Modifier& operator=(Modifier);
  int getEffect() const;
  void setEffect(int);
  int getDuration() const;
  void setDuration(int);
  bool upkeep(); //called by the upkeep func of other classes, decrements duration by one; returns true when mod should be deleted
  virtual void apply(int*);
  virtual string getType();

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

Modifier::Modifier(const Modifier& other){
  effect = other.getEffect();
  duration = other.getDuration();
}

//Modifier::~Modifier(){
//  cout << "Am i doing it right?" << endl;
//}

Modifier& Modifier::operator=(Modifier other){
  this->effect = other.getEffect();
  this->duration = other.getDuration();
  return *this;
}

int Modifier::getEffect() const{
  return effect;
}

void Modifier::setEffect(int eff){
  effect = eff;
}

int Modifier::getDuration() const{
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

void Modifier::apply(int* state){
  cout << "FUCK YOU";
}

string Modifier::getType(){
  cout << "And Fuck ME TOO";
}

#endif
