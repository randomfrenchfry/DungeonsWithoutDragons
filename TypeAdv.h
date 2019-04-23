#ifndef TYPEADV_H
#def TYPEADV_H
#include "Modifier.h"
#include <string>

class TypeAdv : Modifier{
private:
  string type;

public:
  void setType(string);
  string getType();

};

#endif
