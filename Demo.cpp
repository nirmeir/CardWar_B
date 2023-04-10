/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;

int main() {
  Player p1("Alice");
  Player p2("Bob");
  Game game(p1,p2);
  cout<<"stack size is"<<p1.stacksize()<<endl;
  cout<<"stack size is"<<p2.stacksize()<<endl;
  
  game.playAll();


  int sum= p1.cardesTaken()+p2.cardesTaken()+p1.stacksize()+p2.stacksize();
  cout<<"sum is"<<sum<<endl;
  // cout<<"p1 size is"<<p1.Start_stack.size()<<endl;
  // cout<<"p2 size is"<<p2.Start_stack.size()<<endl;
  // cout<<"p1 card taken is"<<p1.cardesTaken()<<endl;
  // cout<<"p2 card taken is"<<p2.cardesTaken()<<endl;

  // game.printLastTurn();
  // game.printLog();
  // game.printWiner();
  // game.printStats();



    
    return 0;
}
  // Create two players with their names 
  //  Player p1("Alice");
  //  Player p2("Bob");

  //  Game game(p1,p2); 
  //  for (int i=0;i<5;i++) {
  //   game.playTurn();
  //  }
  //  game.printLastTurn(); // print the last turn stats. For example:
  //                                                   // Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.
  //                                                   // Alice played 6 of Hearts Bob played 6 of Spades. Draw. Alice played 10 of Clubs Bob played 10 of Diamonds. draw. Alice played Jack of Clubs Bob played King of Diamonds. Bob wins.
  //  cout << p1.stacksize() << endl; //prints the amount of cards left. should be 21 but can be less if a draw was played
  //  cout << p2.cardesTaken() << endl; // prints the amount of cards this player has won. 
  //  game.playAll(); //playes the game untill the end
  //  game.printWiner(); // prints the name of the winning player
  //  game.printLog(); // prints all the turns played one line per turn (same format as game.printLastTurn())
  //  game.printStats();// for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )

