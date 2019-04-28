#ifndef TYPEADV_H
#define TYPEADV_H
#include "Modifier.h"
#include "State.h"
#include <string>
using namespace std;

class TypeAdv : public Modifier{
private:
  string type;

public:
  TypeAdv();
  TypeAdv(int, int, string); // effect duration name
  void setType(string);
  string getType();
  void apply(int*);

};

TypeAdv::TypeAdv() : Modifier(){
  type = "NOTHING";
}

TypeAdv::TypeAdv(int eff, int dur, string nam) : Modifier(eff, dur){
  type = nam;
}

void TypeAdv::apply(int* state){
  *state += getEffect();
}

string TypeAdv::getType(){
  return type;
}

#endif
