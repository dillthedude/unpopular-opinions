#include "defs.h"

void guess(Game &myGame)
{
    string suspectName;
    cout << "Whose unpopular opinion is this?\n";
    for (auto player : myGame.vectorOfPlayers)
    {
        cout << player.opinion << endl;
        getline(cin, suspectName);
        // we need to verify that the name that we type in is the name of a player
        // only after we verify this should we store the suspectName in the Player object

        bool guessIsValid = false;

        string playerNameLowered = player.name;
        transform(playerNameLowered.begin(), playerNameLowered.end(), playerNameLowered.begin(), ::tolower);

        string suspectNameLowered = suspectName;
        transform(suspectNameLowered.begin(), suspectNameLowered.end(), suspectNameLowered.begin(), ::tolower);

        for (auto thePlayer : myGame.vectorOfPlayers)
        {
            if (thePlayer.name == suspectName)
            {
                guessIsValid = true;
            }
        }
        if (guessIsValid != true)
        {
            cout << "guess is not valid\n";
        }
        else
        {
            cout << "Guess is valid\n";
            player.suspect = suspectName;
        }
    }
}

void enterOpinions(Game &myGame)
{
    string playerOpinion;
    string okToProceed;
    for (auto &player : myGame.vectorOfPlayers)
    {
        cout << player.name << " please enter your opinion and press ENTER\n";
        getline(cin, playerOpinion);
        player.opinion = playerOpinion;
    }

    cout << "Is everyone happy with their input? Y/N: ";
    getline(cin, okToProceed);

    while (okToProceed != "y" && okToProceed != "Y" && okToProceed != "n" && okToProceed != "N")
    {
        cout << "Please input Y or N and press ENTER ";
        getline(cin, okToProceed);
    }

    if (okToProceed == "n" || okToProceed == "N")
        cout << "Too bad, we are going to proceed\n";
    else if (okToProceed == "y" || okToProceed == "Y")
        cout << "Ok, then we will proceed.\n";
    else
        cout << "ERROR: invalid value for okToProceed in enterOpinions();\n";
}

void registerPlayers(Game &myGame)
{
    string numberOfPlayersString = "";
    int numberOfPlayers = -1;

    cout << "How many people will be playing? ";
    getline(cin, numberOfPlayersString);
    numberOfPlayers = stoi(numberOfPlayersString); // convert the string to an int
    myGame.numberOfPlayers = numberOfPlayers;      // store the number of players in the Game object

    // get names of players
    string playerName = "";
    for (int i = 0; i < numberOfPlayers; i++)
    {
        cout << "Player " << i + 1 << ": ";
        getline(cin, playerName);
        Player newPlayer;
        newPlayer.name = playerName;
        myGame.vectorOfPlayers.push_back(newPlayer);
    }

    return;
}

void exitProgram()
{
    cout << "Closing program...\nGoodbye!\n";
    return;
}

bool verifyTitleSelection(const string userSelection)
{
    if ((userSelection != "1") && (userSelection != "2"))
        return false;
    else
        return true;
}

int acceptTitleSelection()
{
    string userSelection;

    cout << "\nPlease input number: ";
    getline(cin, userSelection);

    while (!verifyTitleSelection(userSelection))
    {
        cout << "Please make a valid selection: ";
        getline(cin, userSelection);
    }

    if (userSelection == "2")
        return 2;
    else if (userSelection == "1")
        return 1;
    else
        cout << "ERROR in acceptTitleSelection\n";

    return 0;
}

void showTitle()
{
    //cout << std::string(100, '\n');
    cout << "\t\t\t- - - - - - - - - - - - - - - - - -\n";
    cout << "\t\t\tU N P O P U L A R   O P I N I O N S\n";
    cout << "\t\t\t- - - - - - - - - - - - - - - - - -\n";
    cout << "\n";

    cout << " 1)\tNew Game\n"
         << " 2)\tQuit\n";

    return;
}