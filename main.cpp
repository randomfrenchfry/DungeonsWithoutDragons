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
#include <fstream>
using namespace std;

int menu(){
  cout << endl << "1) Take a look around the room" << endl;
  cout << "2) Go to the next room" << endl;
  cout << "3) Display Stats for party" << endl;
  cout << "4) Save and Exit" << endl << endl << endl;
  int opt;
  cin >> opt;
  return opt;
}

void Fight(Player& pla, Npc& ally, bool& hasally, int rocnt){
  Damage tmpD(3);
  TypeAdv tmpTA(0, -1, "claws");
  Weapon tmpW(10, tmpTA);
  Monster mon(20 + (5 * rocnt), 20 + (5 * rocnt), tmpD, tmpW, "Warewolf");
  string tmp = "";
  while(true){

    //player turn
    pla.upkeep();
    cout << "its your turn press 1 to attack!" << endl;
    cin >> tmp;
    Damage tmp = (pla.attack().getDamage());
    mon.takeDamage(tmp);
    //allies turn
    if(hasally && ally.getState().getBaseHealth() <= 0){
      hasally = false;
      cout << "Your Ally has been killed! Avenge him!" << endl;
    }else if(hasally){
      cout << "Your ally attacks the beast!" << endl;
      Damage tmp = (ally.attack().getDamage());
      mon.takeDamage(tmp);
      ally.upkeep();
    }
    //check if monster is dead
    if(mon.getState().getBaseHealth() <= 0){
      cout << "You killed it!" << endl;
      cout << "you get " << 7+3*rocnt << "xp!" << endl;
      pla.addExperience(10*rocnt);
      pla.upkeep();
      break;
    }
    //monster turn
    cout << "The monster attacks ";
    int odds = 1 + rand() % 2;
    if(odds == 1 && hasally){
      cout << "Your ally!" << endl;
      Damage tmp = (mon.attack().getDamage());
      ally.takeDamage(tmp);
      mon.upkeep();
    }else{
      cout << "You!" << endl;
      Damage tmp = (mon.attack().getDamage());
      pla.takeDamage(tmp);
      mon.upkeep();
    }

  }

}


int main(){
  //Start Text
  Damage tmpD(0);
  TypeAdv tmpTA(0, -1, "Rusty");
  Weapon tmpW(20, tmpTA);
  Player player(100, 100, tmpD, tmpW, "playName");
  Npc allies(60, 60, tmpD, tmpW, "Carl");
  bool hasally = false;
  int opt;
  int roomcnt = 0;
  bool freshStart = true;
  ifstream saveFile("Save.txt");
  string agony;
  if(saveFile >> agony){
    cout << "There is a save file. Would you like to load it? y/n" << endl << endl;
    string load;
    cin >> load;
    if(load == "y" || load == "Y"){
      freshStart = false;
      int pbase;
      saveFile >> pbase;
      cout << pbase << " ";
      int xp;
      saveFile >> xp;
      cout << xp << " ";
      string plName;
      saveFile >> plName;
      cout << plName << " ";
      bool hA;
      saveFile >> hA;
      cout << hA << " ";
      int allB;
      saveFile >> allB;
      cout << allB << " ";
      int rC;
      saveFile >> rC;
      cout << rC << " ";
      tmpD = Damage(0);
      tmpTA = TypeAdv(0, -1, "Rusty");
      tmpW = Weapon(20, tmpTA);
      player = Player(pbase, 100, tmpD, tmpW, plName);
      player.addExperience(xp);
      hasally = hA;
      allies = Npc(allB, 60, tmpD, tmpW, "Carl");
      srand(time(nullptr));
      int roomcnt = rC;
      saveFile.close();
    }
  }
  if(freshStart){
    cout << "You wake up in a dank, dark room." << endl;
    cout << "You have no memories of how you got there." << endl;
    cout << "You hear howls, roars, and the pitter patter of little feet." << endl;
    cout << "You are in a dungeon." << endl;
    cout << "The only way to escape is to kill the monsters with the key." << endl;
    cout << "What is your name?" << endl;
    string playName;
    cin >> playName;
    player.setName(playName);
    bool hasally = false;
    srand(time(nullptr));
    int roomcnt = 0;
  }

  //MAIN LOOP
  try{
    while(true){

      opt = menu();
      cout << player.getState().getBaseHealth();
      player.upkeep();
      if(hasally){
        allies.upkeep();
      }

      if(opt == 1){//Look around the room

        int odds = 1 + rand() % 5;
        if(odds >= 1 && odds <= 2 ){//item found
          cout << "You find a helpfull item. It heals you." << endl;
          player.heal(15);
        }else if(odds >= 3 && odds <= 4){//monster found
          cout << "A Goblin jumps out from behind something. FIGHT!" << endl;
          //FUGGin fight
          Fight(player, allies, hasally ,roomcnt);

        }else{//nothing found
          cout << "You find nothing" << endl;
        }
      }else if(opt == 2){//go to next room
        roomcnt++;
        //gain ally or
        //fight Monster or
        //nothinng happends
        int odds = 1 + rand() % 3;

        if(odds == 1 && !hasally){//ally apears
          hasally = true;
          allies.getState().setBaseHealth(60);
          cout << "An ally has joined your party!" << endl;

        }else if( odds == 2){//monster appears
          cout << "A monster was in the next room FIGHT!" << endl << endl;
          Fight(player, allies, hasally, roomcnt);
        }else{
          cout << "The room was empty." << endl << endl;
        }

      }else if(opt == 3){//print stats
        //call print functions of player and all allies
        player.print();
        cout << endl;
        if(hasally){
          allies.print();
          cout << endl;
        }
      }else if(opt == 4){
        cout << "Saving ..";
        ofstream save("Save.txt");
        save << "Valid ";
        save << player.getState().getBaseHealth() << " ";
        //cout << player.getState().getBaseHealth();
        save << player.getExperience() << " ";
        save << player.getName() << " ";
        save << hasally << " ";
        save << allies.getState().getBaseHealth() << " ";
        save << roomcnt;
        cout << "Saved" << endl;
        save.close();
        return 0;
      }else{
        cout << "Wrong input, try again" << endl;
      }
    }
  }catch( runtime_error er ){

  cout << er.what() << endl;
  ofstream save("Save.txt");
  save.close();
  return 1;

  }//end catch
  ofstream save("Save.txt");
  save.close();
  return 0;
}//end Main
