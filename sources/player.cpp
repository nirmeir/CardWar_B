#include "player.hpp"

using namespace std;
using namespace ariel;

int Player::stacksize(){
    return Start_stack.size();
};

int Player::cardesTaken()
{
    return Card_taken.size();
};