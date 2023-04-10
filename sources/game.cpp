
#include "game.hpp"
#include <iostream>
#include <stdio.h>
#include <string>
#include "player.hpp"
#include <stdexcept>
using namespace std;
using namespace ariel;

void Game::playTurn()
{
    this->turn++;
    
    if(&p1==&p2){
        throw std::runtime_error("Error message");
    }

    if (p1.Start_stack.empty() || p2.Start_stack.empty())
    {
        cout << "one of the players is out of cards" << endl;
        // log.push("one of the players is out of cards");
        throw std::runtime_error("Error message");
        return;
    }
    // cout << "playTurn" << endl;
    // cout<<"p1 size is"<<p1.Start_stack.size()<<endl;
    // cout<<"p2 size is"<<p2.Start_stack.size()<<endl;
    // cout << "p1 card is" << p1.Start_stack.back().getValue() << endl;
    // cout << "p2 card is" << p2.Start_stack.back().getValue() << endl;

    int card_p1 = p1.Start_stack.back().getValue();
    int card_p2 = p2.Start_stack.back().getValue();

   
    if(card_p1 == 1 && card_p2 != 1 && card_p2 != 2){
        // cout << "p1 win" << endl;
        this->p1.wins++;
        log.push_back(p1.name + " " + "played" + " " + p1.Start_stack.back().getValueName() + " " + "of" + " " + p1.Start_stack.back().getSuitName() + " " + p2.name + " " + "played" + " " + p2.Start_stack.back().getValueName() + " " + "of" + " " + p2.Start_stack.back().getSuitName() + " " + p1.name + " " + "wins"+ "\n");
    
        p1.Card_taken.push_back(p1.Start_stack.back());
        p1.Start_stack.pop_back();
        p1.Card_taken.push_back(p2.Start_stack.back());
        p2.Start_stack.pop_back();
    }

    else if(card_p2 == 1 && card_p1 != 1 && card_p1 != 2){
        // cout << "p2 win" << endl;
        p2.wins++;
        log.push_back(p1.name + " " + "played" + " " + p1.Start_stack.back().getValueName() + " " + "of" + " " + p1.Start_stack.back().getSuitName() + " " + p2.name + " " + "played" + " " + p2.Start_stack.back().getValueName() + " " + "of" + " " + p2.Start_stack.back().getSuitName() + " " + p2.name + " " + "wins"+ "\n");

        p2.Card_taken.push_back(p2.Start_stack.back());
        p2.Start_stack.pop_back();
        p2.Card_taken.push_back(p1.Start_stack.back());
        p1.Start_stack.pop_back();
    }


    else if (card_p1 > card_p2)
    {
        // cout << "p1 win" << endl;
        this->p1.wins++;
        log.push_back(p1.name + " " + "played" + " " + p1.Start_stack.back().getValueName() + " " + "of" + " " + p1.Start_stack.back().getSuitName() + " " + p2.name + " " + "played" + " " + p2.Start_stack.back().getValueName() + " " + "of" + " " + p2.Start_stack.back().getSuitName() + " " + p1.name + " " + "wins"+ "\n");
    
        p1.Card_taken.push_back(p1.Start_stack.back());
        p1.Start_stack.pop_back();
        p1.Card_taken.push_back(p2.Start_stack.back());
        p2.Start_stack.pop_back();
    }
    else if (card_p1 < card_p2)
    {
        // cout << "p2 win" << endl;
        p2.wins++;
        log.push_back(p1.name + " " + "played" + " " + p1.Start_stack.back().getValueName() + " " + "of" + " " + p1.Start_stack.back().getSuitName() + " " + p2.name + " " + "played" + " " + p2.Start_stack.back().getValueName() + " " + "of" + " " + p2.Start_stack.back().getSuitName() + " " + p2.name + " " + "wins"+ "\n");

        p2.Card_taken.push_back(p2.Start_stack.back());
        p2.Start_stack.pop_back();
        p2.Card_taken.push_back(p1.Start_stack.back());
        p1.Start_stack.pop_back();
    }
    else
    {
        if (p1.Start_stack.size() == 1 || p2.Start_stack.size() == 1)
        {
            cout << "last card the winner is the one with the most card taken" << endl;

            if (p1.Card_taken.size() > p2.Card_taken.size())
            {
                // cout << "p1 win" << endl;
            }
            else
            {
                // cout << "p2 win" << endl;
            }
        }
        log.push_back(p1.name + " " + "played" + " " + p1.Start_stack.back().getValueName() + " " + "of" + " " + p1.Start_stack.back().getSuitName() + " " + p2.name + " " + "played" + " " + p2.Start_stack.back().getValueName() + " " + "of" + " " + p2.Start_stack.back().getSuitName() + " " + "draw" +"\n");
        tie();
    }
};

void Game::tie()
{
    
    draw_amount++;
    // cout << "tie" << endl;
    vector<Card> draw;

    if (p1.Start_stack.empty() || p2.Start_stack.empty())
    {
        // cout << "one of the players is out of cards" << endl;

        for (int i = 0; i < draw.size(); i++)
        {
            if (i % 2 == 0)
            {
                p1.Start_stack.push_back(draw[(size_t)i]);
            }
            else
            {
                p2.Start_stack.push_back(draw[(size_t)i]);
            }
        };
    };

    Card p1_tie = p1.Start_stack.back();
    p1.Start_stack.pop_back();
    Card p2_tie = p2.Start_stack.back();
    p2.Start_stack.pop_back();
    draw.push_back(p1_tie);
    draw.push_back(p2_tie);
    int card_p1 = p1.Start_stack.back().getValue();
    int card_p2 = p2.Start_stack.back().getValue();
    // cout << "p1 card is" << p1.Start_stack.back().getValue() << endl;
    // cout << "p2 card is" << p2.Start_stack.back().getValue() << endl;


    if(card_p1 == 1 && card_p2 != 1 && card_p2 != 2){
            // cout << "p1 win" << endl;
            this->p1.wins++;
            log.push_back(p1.name + " " + "played" + " " + p1.Start_stack.back().getValueName() + " " + "of" + " " + p1.Start_stack.back().getSuitName() + " " + p2.name + " " + "played" + " " + p2.Start_stack.back().getValueName() + " " + "of" + " " + p2.Start_stack.back().getSuitName() + " " + p1.name + " " + "wins"+ "\n");
        
            p1.Card_taken.push_back(p1.Start_stack.back());
            p1.Start_stack.pop_back();
            p1.Card_taken.push_back(p2.Start_stack.back());
            p2.Start_stack.pop_back();
        }

    else if(card_p2 == 1 && card_p1 != 1 && card_p1 != 2){
            // cout << "p2 win" << endl;
            p2.wins++;
            log.push_back(p1.name + " " + "played" + " " + p1.Start_stack.back().getValueName() + " " + "of" + " " + p1.Start_stack.back().getSuitName() + " " + p2.name + " " + "played" + " " + p2.Start_stack.back().getValueName() + " " + "of" + " " + p2.Start_stack.back().getSuitName() + " " + p2.name + " " + "wins"+ "\n");

            p2.Card_taken.push_back(p2.Start_stack.back());
            p2.Start_stack.pop_back();
            p2.Card_taken.push_back(p1.Start_stack.back());
            p1.Start_stack.pop_back();
        }



    else if (card_p1 > card_p2)
    {
        p1.wins++;
        log.push_back(p1.name + " " + "played" + " " + p1.Start_stack.back().getValueName() + " " + "of" + " " + p1.Start_stack.back().getSuitName() + " " + p2.name + " " + "played" + " " + p2.Start_stack.back().getValueName() + " " + "of" + " " + p2.Start_stack.back().getSuitName() + " " + p1.name + " " + "wins"+ "\n");

        // cout << "p1 win" << endl;
        p1.Card_taken.push_back(p1.Start_stack.back());
        p1.Start_stack.pop_back();
        p1.Card_taken.push_back(p2.Start_stack.back());
        p2.Start_stack.pop_back();
        for (int i = 0; i < draw.size(); i++)
        {
            p1.Card_taken.push_back(draw[(size_t)i]);
        }
        draw.clear();
    }
    else if (card_p1 < card_p2)
    {
        p2.wins++;
        log.push_back(p1.name + " " + "played" + " " + p1.Start_stack.back().getValueName() + " " + "of" + " " + p1.Start_stack.back().getSuitName() + " " + p2.name + " " + "played" + " " + p2.Start_stack.back().getValueName() + " " + "of" + " " + p2.Start_stack.back().getSuitName() + " " + p2.name + " " + "wins"+ "\n");

        // cout << "p2 win" << endl;
        p2.Card_taken.push_back(p2.Start_stack.back());
        p2.Start_stack.pop_back();
        p2.Card_taken.push_back(p1.Start_stack.back());
        p1.Start_stack.pop_back();
        for (int i = 0; i < draw.size(); i++)
        {
            p2.Card_taken.push_back(draw[(size_t)i]);
        }
        draw.clear();
    }
    else
    {
         this->turn++;
        tie();
    }
}

void Game::printLastTurn()
{
    cout<<log[log.size()-1]<<endl;
};

void Game::playAll()
{
    // cout << "playAll" << endl;
    while (!p1.Start_stack.empty() && !p2.Start_stack.empty())
    {
        playTurn();
    }
    if (p1.cardesTaken() > p2.cardesTaken())
    {
        // cout << "p1 win" << endl;
    }
    else if (p1.cardesTaken() < p2.cardesTaken())
    {
        // cout << "p2 win" << endl;
    }
    else
    {
        // cout << "tie" << endl;
    }
};

void Game::printWiner()
{
    if (p1.Start_stack.empty() && p2.Start_stack.empty())
    {

        if (p1.cardesTaken() > p2.cardesTaken())
        {
            cout << p1.name + " " + "win the game" << endl;
        }
        else if (p1.cardesTaken() < p2.cardesTaken())
        {
            cout << p2.name + " " + "win the game" << endl;
        }
        else
        {
            cout << "The game is ending with draw" << endl;
        }
    }
    else{
        cout << "game is not over" << endl;
    }
};

void Game::printLog()
{
    for (int i = 0; i < log.size(); i++)
    {
        cout << log[(size_t)i] << endl;
    }
};

void Game::printStats()
{
    double p1_rate = static_cast<double>(p1.wins)/this->turn * 100;
    double p2_rate = static_cast<double>(p2.wins)/this->turn * 100;
    double draws_rate = static_cast<double>(draw_amount)/this->turn * 100;

  
    cout << "p1 win rate is" << p1_rate << "%" << endl;
    cout << "p2 win rate is" << p2_rate << "%" << endl;

    cout << "p1 cardes taken" << p1.cardesTaken() << endl;
    for(int i=0; i<p1.Card_taken.size();i++){
        cout<<p1.Card_taken[(size_t)i].getValueName()<<" "<<p1.Card_taken[(size_t)i].getSuitName()<<endl;
    }
    
     cout << "p2 cardes taken" << p2.cardesTaken() << endl;
    for(int i=0; i<p1.Card_taken.size();i++){
        cout<<p1.Card_taken[(size_t)i].getValueName()<<" "<<p1.Card_taken[(size_t)i].getSuitName()<<endl;
    }


    cout << "draw rate is" << draws_rate << "%" << endl;
    cout << "draw amount is" << draw_amount << endl;

    
};
