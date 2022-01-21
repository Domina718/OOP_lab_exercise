#include "Game.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include <iostream>
using namespace std;

void Game::initializeGame() {
	HumanPlayer human("Domina");
	players.push_back(new HumanPlayer("Domina"));
	for (int i = 1; i < numberOfPlayers; i++) {
		string name = "computer" + to_string(i);
		ComputerPlayer computer(name);
		players.push_back(new ComputerPlayer(name));
	}
}

bool Game::isGameOver() {
	for (auto player : players) {
		if (player->getPoints() == goal) {
			cout << "\nPlayer " << player->getName() << " wins!" << endl;
			return true;
		}
	}

	return false;	
}

void Game::playGame() {
	initializeGame();
	for (auto player : players) {
		cout << "Name " << player->getName() << endl;
	}
	while (!isGameOver()) {
		int totalSum = 0;
		for (auto player : players) {
			player->chooseCoins();
			totalSum += player->getHand();
		}
		cout << "\nSum is " << totalSum << endl;
		for (auto player : players) {
			
			if (totalSum == player->guessSum()) {
				cout << "\nPlayer " << player->getName() << " wins hand!" << endl;
				player->addPoint();
			}
				
		}
		for (auto player : players) {
			player->resetHand();
		}
	}
}
