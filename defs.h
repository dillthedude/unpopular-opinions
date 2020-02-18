#pragma once
#include <iostream>
#include <string>
#include "Game.h"
#ifdef __linux__
#include<bits/stdc++.h> // this is for transform() function in function guess() (linux)
#endif
#ifdef _WIN32
#include <algorithm> // this is for transform() function in function guess() (windows)
#endif
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;

void orderPlayersByPoints(Game & myGame);
void showStandings(Game & myGame);
void showRules();
string lowerString(string name);
void awardPoints(Game & myGame);
void determinePopularityOfOpinions(Game & myGame);
void guess(Game & myGame);
void enterOpinions(Game & myGame);
void registerPlayers(Game & myGame);
void exitProgram();
bool verifyTitleSelection(const string userSelection);
int acceptTitleSelection();
void showTitleOptions();
void showTitle();