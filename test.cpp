#include "Boon.h"
#include "DoT.h"
#include "Curse.h"
#include "TypeAdv.h"
#include "Character.h"
#include "Player.h"
#include "Npc.h"
#include "Monster.h"
#include "Damage.h"
#include "Weapon.h"
#include "State.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;


void fight(vector<Npc> allies){
  cout << "Start fught" << endl;
  for(int i=0; i<allies.size(); i++){
    cout << allies[i].getName() << "Attacks!" << endl;
  }

}

int main(){

  vector<Npc> allies;
  vector<Monster> enemeis;
/*
  Npc stockAllies[4];
  Damage tmpD(3);
  TypeAdv tmpTA(0, -1, "Claymore");
  Weapon tmpW(15, tmpTA);
  Npc all(60, 60, tmpD, tmpW, "Reynold the Warrior");
  stockAllies[0] = all;
  Damage tmpD1(1);
  TypeAdv tmpTA1(0, -1, "Daggars");
  Weapon tmpW1(17, tmpTA1);
  Npc all1(60, 60, tmpD1, tmpW1, "Bella the Thief");
  stockAllies[1] = all1;
  Damage tmpD2(3);
  TypeAdv tmpTA2(0, -1, "Crossbow");
  Weapon tmpW2(15, tmpTA2);
  Npc all2(60, 60, tmpD2, tmpW2, "William the Squire");
  stockAllies[2] = all2;
  Damage tmpD3(3);
  TypeAdv tmpTA3(0, -1, "fireball");
  Weapon tmpW3(15, tmpTA3);
  Npc all3(60, 60, tmpD3, tmpW3, "Big Hat Larry");
  stockAllies[3] = all3;

  Monster stockMons[4];
  Damage tmpDm(1);
  TypeAdv tmpTAm(0, -1, "sticks");
  Weapon tmpWm(7, tmpTAm);
  Monster mon(20, 20, tmpDm, tmpWm, "Goblin");
  stockMons[0] = mon;
  Damage tmpD1m(1);
  TypeAdv tmpTA1m(0, -1, "claws");
  Weapon tmpW1m(11, tmpTA1m);
  Monster mon1(30, 30, tmpD1m, tmpW1m, "Warewolf");
  stockMons[1] = mon1;
  Damage tmpD2m(1);
  TypeAdv tmpTA2m(0, -1, "Club");
  Weapon tmpW2m(15, tmpTA2m);
  Monster mon2(40, 40, tmpD2m, tmpW2m, "Cyclops");
  stockMons[2] = mon2;
  Damage tmpD3m(1);
  TypeAdv tmpTA3m(0, -1, "Sword");
  Weapon tmpW3m(9, tmpTA3m);
  Monster mon3(35, 60, tmpD3m, tmpW3m, "Skelliton");
  stockMons[3] = mon3;


  for(int i=0; i<4; i++){
    stockAllies[i].print();
  }
*/
  for(int i=0; i<3; i++){
    allies.push_back(Npc());
  }

  for(int i=0; i<allies.size(); i++){
    cout << allies[i].getName() << "Attacks!" << endl;
  }
  fight(allies);

  return 0;
}
