#pragma once
#include <string>
using std::string;

class Player
{
public:
    // member functions
    Player();
    ~Player();

    // member variables
    string name;    // the name of the player
    string opinion; // the player's opinion
    string suspect; // the name of the player who is suspected to hold this opinion
};