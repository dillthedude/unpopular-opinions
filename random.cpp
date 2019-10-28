#include "random.h"

Game randomizePlayerOrder(Game myGame)
{
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  shuffle(myGame.vectorOfPlayers.begin(), myGame.vectorOfPlayers.end(), std::default_random_engine(seed));
  return myGame;
}