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

    return 0;
}