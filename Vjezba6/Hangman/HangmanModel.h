#pragma once
#include <iostream>
#include <string>

using namespace std;

class HangmanModel {
	string randMovie;
	int lives;
	string currentStatus;
	string allGuesses;
public:
	HangmanModel() { currentStatus = ""; lives = 7; allGuesses = ""; }
	void randomMovie();
	void incognito();
	string getRandMovie() const;
	string getCurrentStatus() const;
	void setCurrentStatus(string);
	int getLives() const;
	void decreaseLivesByOne();
	void setAllGuesses(char);
	string getAllGuesses();
};