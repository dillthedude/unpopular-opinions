#include "defs.h"
#include "Game.h"
#include "random.h"

int main()
{
    Game myGame;
    int titleSelection = -1;

    showTitle(); // title
    do
    {
        showTitleOptions();
        titleSelection = acceptTitleSelection();
        if (titleSelection == -1)
            cout << "ERROR in main(), titleSelection == -1"; // for testing purposes only
        if (titleSelection == 3)
        {
            exitProgram();
            return 0;
        }
        if (titleSelection == 2)
            showRules();
    } while (titleSelection != 1);
    registerPlayers(myGame);
    enterOpinions(myGame);
    myGame = randomizePlayerOrder(myGame);
    guess(myGame);
    myGame = randomizePlayerOrder(myGame);
    determinePopularityOfOpinions(myGame);
    awardPoints(myGame);

    showStandings(myGame);

    return 0;
}