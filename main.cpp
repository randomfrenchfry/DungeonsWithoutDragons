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
using namespace std;

int menu(){
  cout << "1) Take a look around the room" << endl;
  cout << "2) Go to the next room" << endl;
  cout << "3) Display Stats for party" << endl;
  int opt;
  cin >> opt;
  return opt;
}

void Fight(Player pla, Npc* ally, int numAlly, Monster mon){

}


int main(){
  //Start Text
  cout << "You wake up in a dank, dark room." << endl;
  cout << "You have no memories of how you got there." << endl;
  cout << "You hear howls, roars, and the pitter patter of little feet." << endl;
  cout << "You are in a dungeon." << endl;
  cout << "The only way to excape is to kill the monster with the key." << endl;
  cout << "What is your name?" << endl;
  string playName;
  cin >> playName;
  Damage tmpD(0);
  TypeAdv tmpTA(0, -1, "Rusty");
  Weapon tmpW(20, tmpTA);
  Player player(100, 100, tmpD, tmpTA, playName);
  Npc* allies = new Npc[0];
  int numAllies = 0;
  srand(time(nullptr));
  int opt;

  //MAIN LOOP
  while(true){

    opt = menu();

    if(opt == 1){//Look around the room
      int odds = 1 + rand() % 5;
      if(odds >= 1 && odds <= 2 ){//item found
        cout << "You find a helpfull item" << endl;
      }else if(odds >= 3 && odds <= 4){//monster found
        cout << "A Monster jumps out from behind something. FIGHT!" << endl;
        Damage tmpD(1);
        TypeAdv tmpTA(0, -1, "Goblin");
        Weapon tmpW(10, tmpTA);
        Monster tmpMon(40, 40, tmpD, tmpTA, playName);
        //FUGGin fight
        Fight(player, allies, numAllies ,tmpMon);

      }else{//nothing found
        cout << "You find nothing" << endl;
      }

    }else if(opt == 2){//go to next room

    }else if(opt == 3){//print stats

    }else{
      cout << "Wrong input, try again" << endl;
    }

  }



  return 0;
}
