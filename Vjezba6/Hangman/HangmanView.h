#pragma once
#include <iostream>
#include "HangmanController.h"
#include <vector>
using namespace std;

class HangmanView {
	HangmanController ctrl;
	vector<string> drawingTemplates;
public:
	HangmanView() { drawings(); }
	void displayHangman();
	void displayCurrentStatus();
	void displayAllGuesses();
	void displayLivesLeft();
	void drawings();
	void start();
	
};