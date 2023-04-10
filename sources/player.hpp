#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include <stack>
#include "card.hpp"

using namespace std;

namespace ariel
{
    
    class Player
    { 

    public:
        vector<Card> Start_stack;
        vector<Card> Card_taken;
        string name ;
        int wins=0;
        
        Player(string name) : name(std::move(name))
        {
           
        };


        int stacksize();

        int cardesTaken();
      
};
}