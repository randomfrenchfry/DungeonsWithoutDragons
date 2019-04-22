#ifndef DAMAGE_H
#def DAMAGE_H

class Damage{
public:
  Damage();
  
  Damage operator+(Damage other);

private:
  int damage;
  TypeAdv* typeAdvanteges;

};

#endif
