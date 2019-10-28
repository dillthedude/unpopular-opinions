#pragma once
#include "Player.h"
#include <vector>
#include <string>
using std::string;
using std::vector;

class Game
{
public:
    // member functions
    Game();
    ~Game();

    // member variables
    unsigned int numberOfPlayers;
    vector<Player> vectorOfPlayers;
};