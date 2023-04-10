#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

namespace ariel
{

    class Card
    {

    public:
        enum Suit
        {
            SPADES,
            HEARTS,
            CLUBS,
            DIAMONDS
        };

        enum Cards{
            ACE=1,
            TWO,
            THREE,
            FOUR,
            FIVE,
            SIX,
            SEVEN,
            EIGHT,
            NINE,
            TEN,
            PRINCE,
            QUEEN,
            KING
        };

    private:
        int value;
        Suit suit;

    public:
        Card(int m_value, Suit m_suit) : value(m_value), suit(m_suit) {}

        int getValue() const
        {
            return value;
        }

        Suit getSuit() const
        {
            return suit;
        }

        int get_size();

        static vector<Card> Create_cards()
        {
            cout << "create cards" << endl;

            std::vector<Card> deck;
            cout << "create vector" << endl;
            int index = 0;
            for (int suit = Card::SPADES; suit <= Card::DIAMONDS; suit++)
            {
                for (int value = ACE; value <= KING; value++)
                {
                    deck.push_back(Card(value, (Card::Suit)suit));
                    // get the value of the card from the deck
                    //  cout<<"deck value is"<<deck[(size_t)index].getValue()<<endl;
                    //  cout<<"deck value is"<<deck[(size_t)index].getSuitName()<<endl;
                    //  index++;
                }
                // cout<<"deck size is"<<deck.size()<<endl;
                // cout<<"#############################################"<<endl;
            }
            srand(time(0));
            random_shuffle(deck.begin(), deck.end());
            cout << "inside shuffle" << endl;
            cout << "deck size is" << deck.size() << endl;

            return deck;
        }

        //     static vector<Card> Shuffle(){

        //     vector<Card> deck = Create_cards();
        //     srand(time(0));
        //     random_shuffle(deck.begin(), deck.end());
        //     cout<<"inside shuffle"<<endl;
        //     cout<<"deck size is"<<deck.size()<<endl;
        //     return deck;
        // }

        string getSuitName() const
        {
            switch (suit)
            {
            case HEARTS:
                return "Hearts";
            case DIAMONDS:
                return "Diamonds";
            case CLUBS:
                return "Clubs";
            case SPADES:
                return "Spades";
            }
            return "Unknown";
        }

        string getValueName() const
        {
            switch (value)
            {
            case ACE:
                return "Ace";
            case TWO:
                return "2";
            case THREE:
                return "3";
            case FOUR:
                return "4";
            case FIVE:
                return "5";
            case SIX:
                return "6";
            case SEVEN:
                return "7";
            case EIGHT:
                return "8";
            case NINE:
                return "9";
            case TEN:
                return "10";
            case PRINCE:
                return "Prince";
            case QUEEN:
                return "Queen";
            case KING:
                return "King";
            }
            return "Unknown";
        }
    };
}
