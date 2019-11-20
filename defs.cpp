#include "defs.h"

void showStandings(Game &myGame)
{
	cout << "Current standings:\n\n";
	
}

void showRules()
{
	string rule1 = "Rule number one.";
	string rule2 = "Rule number two.";
	string rule3 = "Rule number three.";
	string rule4 = "Rule number four.";
	string rule5 = "Rule number five.";
	
	cout << "\t\t\t- - - - -\n";
	cout << "\t\t\tR U L E S\n";
	cout << "\t\t\t- - - - -\n";
	cout << endl;
	cout << " \u261b " << rule1 << endl;
	cout << " \u261b " << rule2 << endl;
	cout << " \u261b " << rule3 << endl;
	cout << " \u261b " << rule4 << endl;
	cout << " \u261b " << rule5 << endl;
	cout << endl;

}

string lowerString(string name)
{
	string loweredName = name;
	transform(loweredName.begin(), loweredName.end(), loweredName.begin(), ::tolower);
	return loweredName;
}

void awardPoints(Game &myGame)
{
	int pointsWon;

	cout << "Time to award points!\n\n";
	for (auto player : myGame.vectorOfPlayers)
	{
		pointsWon = 0;
		cout << "Opinion: " << player.opinion << endl;
		cout << "Suspect: " << player.suspect << endl;
		cout << "It was " << player.name << "'s opinion!\n";
		cout << player.numberOfPlayersWithThisOpinion << " out of " << myGame.vectorOfPlayers.size() << " players hold this opinion. This opinion is ";
		if (player.numberOfPlayersWithThisOpinion == 0)
			cout << "VERY UNPOPULAR. :[ ";
		else if ((myGame.vectorOfPlayers.size() / player.numberOfPlayersWithThisOpinion) >= 2)
			cout << "UNPOPULAR. ";
		else
			cout << "POPULAR. ";

		if (player.numberOfPlayersWithThisOpinion != 0 && (lowerString(player.name) != lowerString(player.suspect)) )
			pointsWon = myGame.vectorOfPlayers.size() / player.numberOfPlayersWithThisOpinion;
		player.pointsAwarded += pointsWon;

		if (pointsWon == 1)
			cout << pointsWon << " point awarded.\n";
		else
			cout << pointsWon << " points awarded.\n";
		cout << player.name << "'s total points: " << player.pointsAwarded << endl;
		cout << endl;
	}

	return;
}

void determinePopularityOfOpinions(Game &myGame)
{
	string numberOfPlayersWithStatedOpinion_String;
	int numberOfPlayersWithStatedOpinion_int = -1;
	bool okToConvertStringToInt = true;

	cout << "Next phase!\n";

	for (auto &player : myGame.vectorOfPlayers)
	{
		numberOfPlayersWithStatedOpinion_int = -1;
		numberOfPlayersWithStatedOpinion_String = "";
		bool firstPass = true;
		cout << player.opinion << endl;
		cout << "How many players feel this way? ";

		do
		{
			if (!firstPass)
				cout << "Your input was not valid. Please enter a number from 1 to " << myGame.numberOfPlayers << endl;
			firstPass = false;
			getline(cin, numberOfPlayersWithStatedOpinion_String);
			okToConvertStringToInt = true;
			for (char &c : numberOfPlayersWithStatedOpinion_String)
				if (!isdigit(c))
					okToConvertStringToInt = false;
			if (numberOfPlayersWithStatedOpinion_String == "")
				okToConvertStringToInt = false;
			if (okToConvertStringToInt == true)
				numberOfPlayersWithStatedOpinion_int = stoi(numberOfPlayersWithStatedOpinion_String);
		}
		while ((numberOfPlayersWithStatedOpinion_int < 0) || (numberOfPlayersWithStatedOpinion_int > myGame.numberOfPlayers));
		player.numberOfPlayersWithThisOpinion = numberOfPlayersWithStatedOpinion_int;
		cout << endl;
	}
}

void guess(Game &myGame)
{
	string suspectName;
	for (auto &player : myGame.vectorOfPlayers)
	{
		cout << "Whose unpopular opinion is this?\n";
		bool guessIsValid = false; // start off assuming that the guess is not valid
		do
		{
			cout << player.opinion << endl;
			getline(cin, suspectName);

			// lowered version of the guess
			string suspectNameLowered = suspectName;
			transform(suspectNameLowered.begin(), suspectNameLowered.end(), suspectNameLowered.begin(), ::tolower);

			for (auto thePlayer : myGame.vectorOfPlayers)
			{
				// lowered version of the player's name we are checking against
				string playerNameLowered = thePlayer.name;
				transform(playerNameLowered.begin(), playerNameLowered.end(), playerNameLowered.begin(), ::tolower);

				if (playerNameLowered == suspectNameLowered)
					guessIsValid = true;
			}
			if (guessIsValid == false)
				cout << "Guess is not valid. Please enter the name of a player.\nOpinion: ";
			else
			{
				player.suspect = suspectName;
				cout << endl;
			}
		} while (guessIsValid == false);
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

	cout << endl;
}

void registerPlayers(Game &myGame)
{
	string numberOfPlayersString = "";
	int numberOfPlayers = -1;

	cout << "How many people will be playing? ";
	getline(cin, numberOfPlayersString);
	numberOfPlayers = stoi(numberOfPlayersString); // convert the string to an int
	myGame.numberOfPlayers = numberOfPlayers;	  // store the number of players in the Game object

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
	cout << endl;
	return;
}

void exitProgram()
{
	cout << "Closing program...\nGoodbye!\n";
	return;
}

bool verifyTitleSelection(const string userSelection)
{
	if ((userSelection != "1") && (userSelection != "2") && (userSelection != "3") )
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
	else if (userSelection == "3")
		return 3;
	else
		cout << "ERROR in acceptTitleSelection\n";

	return 0;
}

void showTitleOptions()
{
	

	cout << " 1)\tNew Game\n"
		 << " 2)\tRules\n"
		 << " 3)\tQuit\n";
}

void showTitle()
{
	//cout << std::string(100, '\n');
	cout << "\t\t\t- - - - - - - - - - - - - - - - - -\n";
	cout << "\t\t\tU N P O P U L A R   O P I N I O N S\n";
	cout << "\t\t\t- - - - - - - - - - - - - - - - - -\n";
	cout << "\n";
}