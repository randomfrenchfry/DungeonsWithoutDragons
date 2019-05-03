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

int menu(){
  cout << endl << "1) Take a look around the room" << endl;
  cout << "2) Go to the next room" << endl;
  cout << "3) Display Stats for party" << endl << endl << endl;
  int opt;
  cin >> opt;
  return opt;
}

void Fight(Player& pla, vector<Npc> ally, vector<Monster> mons, int rocnt){
  int totxp = 0;
  int tmp;
  while(true){

    //player turn
    pla.upkeep();
    cout << "Its your turn choose who to attack!" << endl;
    for(int i=0; i<mons.size();i++){
      if(mons[i].getState().getBaseHealth() > 0){
        cout << i+1 << ") " << mons[i].getName() << endl;
      }
    }
    cin >> tmp;
    Damage tmpD = (pla.attack().getDamage());
    cout << tmpD.getDamage() << endl;
    cout << mons[tmp-1].getState().getBaseHealth() << " : ";
    mons[tmp-1].takeDamage(tmpD);
    cout << mons[tmp-1].getState().getBaseHealth();
    cout << "Made It" << endl;
    //check for dead monsters
    for(int i=0;i<mons.size();i++){
      if(mons[i].getState().getBaseHealth() <= 0){
        totxp += 5 +  3 * rocnt;
        vector<Monster>::iterator it = mons.begin() + i;
        mons.erase(it);
      }
    }
    if(mons.size()==0){
      cout << "Yall defeted all the monsters." << endl;
      pla.addExperience(totxp);
      break;
    }
    //allies turn
    for(int i=0;i<ally.size(); i++){
      ally[i].upkeep();
      int odds = rand() % mons.size();
      cout << ally[i].getName() << " attacks " << mons[odds].getName() << endl;
      tmpD = (ally[i].attack().getDamage());
      mons[odds].takeDamage(tmpD);

    }
    //check if monster is dead
    for(int i=0;i<mons.size();i++){
      if(mons[i].getState().getBaseHealth() <= 0){
        totxp += 5 +  3 * rocnt;
        vector<Monster>::iterator it = mons.begin() + i;
        mons.erase(it);
      }
    }
    if(mons.size()==0){
      cout << "Yall defeted all the monsters." << endl;
      pla.addExperience(totxp);
      break;
    }
    //check if all monstors are dead - mons is empty
    //monster turn
    for(int i=0; i<mons.size(); i++){
      mons[i].upkeep();
      int odds = rand() % (ally.size()+1);
      if(odds < ally.size()){
        cout << mons[i].getName() << " attacks " << ally[odds].getName() << endl;
        tmpD = (mons[i].attack().getDamage());
        ally[odds].takeDamage(tmpD);
      }else{
        cout << mons[i].getName() << "attacks you!" << endl;
        tmpD = (mons[i].attack().getDamage());
        pla.takeDamage(tmpD);
      }
    }
    for(int i=0;i<ally.size(); i++){
      if(ally[i].getState().getBaseHealth() <= 0){
        vector<Npc>::iterator it = ally.begin() + i;
        ally.erase(it);
      }
    }
  }

}


int main(){
  //creating cast of allies
  cout << "Start of Main" << endl;

  Npc stockAllies[4];

  Damage tmpD(3);
  TypeAdv tmpTA(0, -1, "Claymore");
  Weapon tmpW(15, tmpTA);
  Npc all(60, 60, tmpD, tmpW, "Reynold the Warrior");
  stockAllies[0] = all;
  /*
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
  */
  //creating cast of monsters
  cout << "monsters" << endl << endl << endl;

  Monster stockMons[4];
  /*
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
  */
  //Start Text2
  cout << "You wake up in a dank, dark room." << endl;
  cout << "You have no memories of how you got there." << endl;
  cout << "You hear howls, roars, and the pitter patter of little feet." << endl;
  cout << "You are in a dungeon." << endl;
  cout << "The only way to escape is to kill the monster with the key." << endl;
  cout << "What is your name?" << endl;
  string playName;
  cin >> playName;
  Damage tmpDp(0);
  TypeAdv tmpTAp(0, -1, "Rusty");
  Weapon tmpWp(20, tmpTAp);
  Player player(100, 100, tmpDp, tmpWp, playName);//player
  vector<Npc> allies;//allies
  vector<Monster> enimies;//monsters
  //Npc allies(60, 60, tmpD, tmpW, "Carl");
  //bool hasally = false;
  srand(time(nullptr));
  int opt;
  int roomcnt = 0;

  //MAIN LOOP
  try{
    while(true){

      opt = menu();
      player.upkeep();
      for(int i=0; i<allies.size(); i++){//ally upkeep
        allies[i].upkeep();
      }

      if(opt == 1){//Look around the room

        int odds = 1 + rand() % 5;
        if(odds >= 1 && odds <= 2 ){//item found
          cout << "You find a helpfull item. It heals you." << endl;
          player.heal(15);
        }else if(odds >= 3 && odds <= 4){//monster found
          enimies.push_back(stockMons[0]);
          cout << "A Goblin jumps out from behind something. FIGHT!" << endl;
          //FUGGin fight
          Fight(player, allies, enimies ,roomcnt);

        }else{//nothing found
          cout << "You find nothing" << endl;
        }
      }else if(opt == 2){//go to next room
        roomcnt++;
        //gain ally or
        //fight Monster or
        //nothinng happends
        int odds = 1 + rand() % 3;

        if(odds == 1){//ally apears
          //hasally = true;
          //allies.getState().setBaseHealth(60);
          cout << "An ally has joined your party!" << endl;
          int odds = rand() % 4;
          allies.push_back(stockAllies[odds]);
        }else if( odds == 2){//monster appears
          cout << "A monster was in the next room FIGHT!" << endl << endl;
          int odds = 1 + rand() % 3;
          for(int i=0; i<odds;i++){
            int odds2 = rand() % 4;
            enimies.push_back(stockMons[odds2]);
          }
          Fight(player, allies, enimies, roomcnt);
        }else{
          cout << "The room was empty." << endl << endl;
        }

      }else if(opt == 3){//print stats
        //call print functions of player and all allies
        player.print();
        cout << endl;
        for(int i=0; i<allies.size(); i++){
          allies[i].print();
        }
      }else{
        cout << "Wrong input, try again" << endl;
      }
    }
  }catch( runtime_error er ){

  cout << er.what() << endl;
  return 1;

  }//end catch

  return 0;
}//end Main
