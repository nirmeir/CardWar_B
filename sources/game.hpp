#pragma once
#include <iostream>
#include <stdio.h>
#include "player.hpp"

namespace ariel
{

    class Game
    {
    public:
        Player &p1;
        Player &p2;
        int draw_amount = 0;
        vector<string> log;
        int turn = 0;


        Game(Player &player1, Player &player2) : p1(player1), p2(player2)
        {
            vector<Card> deck = Card::Create_cards();
            
            for (int i = 0; i < deck.size(); i++)
            {
                // cout<<"the i is"<<i<<endl;

                if (i % 2 == 0)
                {
                    // cout<<"inside even "<<i<<endl;
                    p1.Start_stack.push_back(deck[(size_t)i]);
                    
                }
                else
                {
                    // cout<<"inside odd "<<i<<endl;
                     p2.Start_stack.push_back(deck[(size_t)i]);
                }
            };
        };


        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
        void tie();  
    };
}
