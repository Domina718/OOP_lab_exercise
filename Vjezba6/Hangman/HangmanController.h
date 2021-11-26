#pragma once
#include <iostream>
#include <string>
#include "HangmanModel.h"
using namespace std;

class HangmanController {
	char input;
	HangmanModel model;
public:
	void initialize();
	void userEntry();
	bool isValidInput();
	bool isRepeatedInput();
	bool checkLetter() const;
	void updateCurrentStatus();
	void updateLives();
	string getCurrentStatus();
	string getAllGuesses();
	int getLives();
	bool isGameOver();
	bool isGameWon();
	
};