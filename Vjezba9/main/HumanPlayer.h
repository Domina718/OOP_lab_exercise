#pragma once
#include "Player.h"

class HumanPlayer : public Player {
public:
	HumanPlayer(string name) { this->points = 0; this->name = name; this->hand = 0; };
	void chooseCoins();
	int guessSum();
private:
	int chooseNumber();
};