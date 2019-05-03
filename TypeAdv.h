#ifndef TYPEADV_H
#define TYPEADV_H
#include "Modifier.h"
#include "State.h"
#include <string.h>
using namespace std;

class TypeAdv : public Modifier{
protected:
  string type;

public:
  TypeAdv();
  TypeAdv(int, int, string); // effect duration name
  TypeAdv(const TypeAdv&);
  ~TypeAdv();
  TypeAdv& operator=(TypeAdv);
  void setType(string);
  string getType() const;
  void apply(int*);

};

TypeAdv::TypeAdv() : Modifier(){
  type = "NOTHING";
}

TypeAdv::TypeAdv(int eff, int dur, string nam) : Modifier(eff, dur){
  type = "aghhh";
}

TypeAdv::~TypeAdv(){
}

TypeAdv::TypeAdv(const TypeAdv& other) : Modifier(other){
  type = other.getType();
}

TypeAdv& TypeAdv::operator=(TypeAdv other){
  Modifier::operator=(other);
  this->type = other.getType();
  return *this;
}

void TypeAdv::apply(int* state){
  *state += getEffect();
}

void TypeAdv::setType(string typ){
  type = typ;
}

string TypeAdv::getType() const{
  return type;
}

#endif
