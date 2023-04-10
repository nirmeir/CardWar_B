#include <iostream>
#include <stack>
#include <random>
#include "card.hpp"

using namespace std;

namespace ariel
{    

    //  vector<Card> Card::Create_cards()
    // {
    //     std::vector<Card> deck;
    //     for (int suit = Card::HEARTS; suit <= Card::SPADES; suit++)
    //     {
    //         for (int value = 1; value <= 13; value++)
    //         {
    //             deck.push_back(Card(value, (Card::Suit)suit));
    //         }
    //     }
    //     return deck;
    // }

    // Shuffle the deck
    // static vector<Card> Card::Shuffle()
    // {
    //     vector<Card> deck = Create_cards();

    //     for (size_t i = deck.size() - 1; i > 0; i--)
    //     {
    //         unsigned int j = (size_t)std::rand() % deck.size();
    //         // int j = std::rand() % (i + 1);
    //         Card temp = deck[j];
    //         deck[i] = deck[j];
    //         deck[j] = temp;
    //     }
    //     return deck;
    // }
}

// while (!deck.empty())
// {
//     v_deck.push_back(deck.top());
//     deck.pop();
// }
// int random_num = std::rand() % v_deck.size();
// std::shuffle(v_deck.begin(), v_deck.end(), random_num);
// for (const auto &card : v_deck)
// {
//     deck.push(card);
// }

// std::cout << "Deck size after shuffle: " << deck.size() << std::endl;

// int main()
// {
//     vector<Card> deck = Shuffle();
//     while (!deck.empty())
//     {
//         Card card = deck[52];
//         std::cout << card.getValue() << " of " << card.getSuitName() << std::endl;
//         deck.pop_back();
//     }
//     return 0;
// }
