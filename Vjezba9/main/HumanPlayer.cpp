#include "HumanPlayer.h"
#include <iostream>
using namespace std;



void HumanPlayer::chooseCoins() {
	int numOfCoins, entry;
	cout << "\nHow many coins would you like to play with?  ";
	cin >> numOfCoins;
	while (numOfCoins > 3 || numOfCoins < 0) {
		cout << "\nWrong input! Please choose a number between 0 (zero) and 3 (three)." << endl;
		cout << "\nInput number of coins here -- ";
		cin >> numOfCoins;
	}
	if (numOfCoins == 3)
		this->hand = 8;
	else if (numOfCoins == 0)
		this->hand = 0;
	else if (numOfCoins == 1) {
		entry = chooseNumber();
		this->hand = entry;
	}
	else {
		entry = chooseNumber();
		int entry2 = chooseNumber();
		while (entry == entry2)
			entry2 = chooseNumber();
		this->hand = entry + entry2;
	}
}

int HumanPlayer::chooseNumber() {
	int entry;
	cout << "\nEnter 1, 2 or 5 to choose that coin -->";
	cin >> entry;
	while (entry != 1 && entry != 2 && entry != 5) {
		cout << "\nHey buddy! ....Enter again -->";
		cin >> entry;
	}
	return entry;
}

int HumanPlayer::guessSum() {
	int guess;
	cout << "\nMake your guess on the total sum --> ";
	cin >> guess;
	return guess;
}