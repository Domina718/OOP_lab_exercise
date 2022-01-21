#include <iostream>
#include "Game.h"
#include "ComputerPlayer.h"
#include "HumanPlayer.h"
#include <time.h>
#include <random>

using namespace std;

int main()
{
	srand(time(NULL));

	Game japaneza(3,4);
	japaneza.playGame();

}
