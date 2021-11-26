#include "HangmanController.h"
#include <algorithm>
#include <cctype>
using namespace std;

void HangmanController::updateLives() {

	model.decreaseLivesByOne();
}

void HangmanController::userEntry() {

	cout << "\nEnter a letter or number please: ";
	cin >> this->input;

	if (!isValidInput()) {
		cout << "Wrong input! Not a letter or a number. Try again.\n";
		return;
	}
	if (isRepeatedInput()) {
		cout << "Repeated input. Please concentrate.\n";
		return;
	}

	this->input = tolower(this->input);
	model.setAllGuesses(this->input);
	model.setAllGuesses(',');
	updateCurrentStatus();
}

bool HangmanController::isValidInput() {

	return isalnum(this->input);
}

bool HangmanController::isRepeatedInput() {

	return (model.getAllGuesses().find(this->input) != string::npos);
}
bool HangmanController::checkLetter() const {

	return (model.getRandMovie().find(this->input) != string::npos);
}

bool HangmanController::isGameOver() {

	return (model.getLives() ? false : true);
}

bool HangmanController::isGameWon() {

	return(model.getCurrentStatus().find('_') == string::npos);
}


void HangmanController::updateCurrentStatus() {
	if (checkLetter()) {
		int size = model.getRandMovie().size();
		string randMovie = model.getRandMovie();
		string temp;
		temp.push_back(this->input);
		string currentStatus = model.getCurrentStatus();
		for (int i = 0; i < size; i++) {
			if (randMovie[i] == this->input)
				currentStatus.replace(2 * i, 1, temp);
		}
		model.setCurrentStatus(currentStatus);
	}
	else {
		updateLives();
	}	
}

string HangmanController::getCurrentStatus() {
	
	return model.getCurrentStatus();
}
string HangmanController::getAllGuesses() {

	return model.getAllGuesses();
}

int HangmanController::getLives() {

	return model.getLives();
}

void HangmanController::initialize() {

	model.randomMovie();
	model.incognito();
}
