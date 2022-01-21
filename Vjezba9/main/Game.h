#pragma once
#include <vector>
#include <string>
#include "Player.h"
#include <iomanip>

class Game {
	vector<Player*> players;
	int numberOfPlayers;
	int goal;
	void initializeGame();
public:
	Game(int goal, int numberOfPlayers) { this->goal = goal; this->numberOfPlayers = numberOfPlayers; };
	bool isGameOver();
	void playGame();

};