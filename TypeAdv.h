#ifndef TYPEADV_H
#define TYPEADV_H
#include "Modifier.h"
#include <string>

class TypeAdv : Modifier{
private:
  string type;

public:
  void setType(string);
  string getType();

};

void TypeAdv::apply(State& state){
  state.strengthen(getEffect());
}

#endif
