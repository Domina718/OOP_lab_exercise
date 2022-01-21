#include "ComputerPlayer.h"
#include <time.h>
#include <random>
#include <iostream>

using namespace std;

void ComputerPlayer::chooseCoins() {
	int coins[] = { 1,2,5 };
	int numOfCoins = rand() % 4;
	if (numOfCoins == 3)
		this->hand = 8;
	else if (numOfCoins == 0)
		this->hand = 0;
	else if (numOfCoins == 1) {
		this->hand = coins[rand() % 3];
	}
	else {
		int n = rand() % 3;
		int m = n + 1;
		if (m > 2)
			m %= 3;
		this->hand = coins[n] + coins[m];
	}
	cout << "\n" << name << " made his choice." << endl;
}

int ComputerPlayer::guessSum() {
	
	return this->hand * (rand() % (3 + rand() % 3 + 1)) - rand()%3 + 1;
}

