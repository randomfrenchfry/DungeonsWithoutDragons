#ifndef TYPEADV_H
#define TYPEADV_H
#include "Modifier.h"
#include "State.h"
#include <string>
using namespace std;

class TypeAdv : Modifier{
private:
  string type;

public:
  void setType(string);
  string getType();
  void apply(int&);

};

void TypeAdv::apply(int& state){
  state += getEffect();
}

#endif
