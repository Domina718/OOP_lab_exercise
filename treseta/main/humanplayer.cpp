#include "humanplayer.h"
#include <iostream>
#include "player.h"
#include <vector>

using namespace std;

card humanplayer::play_card() {
	int n;
	card c;

	cout << "\nYour hand:" << endl;
	show_hand();
	cout << "\nNumber of card you want to play?  ";
	cin >> n;
	cout << endl;

	while (n > hand.size() || n < 1)
	{
		cout << "\nWrong input. Try again" << endl;
		cin >> n;
	}

	c = hand[n-1];
	cout << this->name << " played " << c << endl;
	auto it = hand.begin() + (n-1);
	hand.erase(it);

	return c;
}

bool humanplayer::is_valid_move(card card_played, int n) {
	if (n > hand.size() || n < 1) {
		cout << "\nWrong input. Try again" << endl;
		return false;
	}

	for (auto card : hand) {
		if (card.get_suit() == card_played.get_suit()) {
			if (card_played.get_suit() != hand[n-1].get_suit()) {
				cout << "\nYou did not answer! Enter card with correct suit";
				return false;
			}
		}
	}

	return true;
}

card humanplayer::play_card(card &card_played) {
	int n;
	card c;

	cout << "\nYour hand:" << endl;
	show_hand();
	cout << "\nNumber of card you want to play for second turn? ";
	cin >> n;
	cout << endl;

	while (!is_valid_move(card_played, n)) {
		cout << "\nNew entry: ";
		cin >> n;
	}

	c = hand[n -1];
	cout << this->name << " played in second turn " << c << endl;
	auto it = hand.begin() + (n-1);
	hand.erase(it);

	return c;
}

