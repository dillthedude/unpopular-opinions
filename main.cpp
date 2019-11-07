#include "defs.h"
#include "Game.h"
#include "random.h"

int main()
{
    Game myGame;
    int titleSelection = -1;

    showTitle(); // title screen
    titleSelection = acceptTitleSelection();
    if (titleSelection == -1)
        cout << "ERROR in main(), titleSelection == -1"; // for testing purposes only
    if (titleSelection == 2)
    {
        exitProgram();
        return 0;
    }
    registerPlayers(myGame);
    enterOpinions(myGame);
    myGame = randomizePlayerOrder(myGame);
    guess(myGame);
    myGame = randomizePlayerOrder(myGame);
    determinePopularityOfOpinions(myGame);

    awardPoints(myGame);

    /*
    for(auto player : myGame.vectorOfPlayers)
    {
        cout << "Player Name: " << player.name << endl;
        cout << "Player Opinion: " << player.opinion << endl;
        cout << "Suspected Player: " << player.suspect << endl;
        cout << "Number of players with this opinion: " << player.numberOfPlayersWithThisOpinion << endl << endl;
    }*/

    return 0;
}