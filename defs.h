#pragma once
#include <iostream>
#include <string>
#include "Game.h"
#include<bits/stdc++.h> // this is for transform() function in function guess()
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;

void awardPoints(Game & myGame);
void determinePopularityOfOpinions(Game & myGame);
void guess(Game & myGame);
void enterOpinions(Game & myGame);
void registerPlayers(Game & myGame);
void exitProgram();
bool verifyTitleSelection(const string userSelection);
int acceptTitleSelection();
void showTitle();