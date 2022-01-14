#include "humanplayer.h"
#include <iostream>
#include "player.h"
#include <vector>

using namespace std;

card humanplayer::play_card() {
	int n;
	card c;
	cout << "Number of card you want to play?  ";
	cin >> n;
	while (n > hand.size())
	{
		cout << "Wrong input. Try again" << endl;
		cin >> n;
	}
	c = hand[n + 1];
	auto it = hand.begin() + n;
	hand.erase(it);
	return c;
}

bool humanplayer::is_valid_move(card card_played, int n) {
	if (n > hand.size()) {
		cout << "Wrong input. Try again" << endl;
		return false;
	}
	for (auto card : hand) {
		if (card.get_suit() == card_played.get_suit()) {
			if (card_played.get_suit() != hand[n+1].get_suit()) {
				cout << "You did not answer! Enter card with correct suit";
				return false;
			}
		}
	}
	return true;
}

card humanplayer::play_card(card card_played) {
	int n;
	card c;
	cout << "Number of card you want to play?  ";
	cin >> n;
	if (is_valid_move(card_played, n) && card_played.get_suit() != c.get_suit()) {
		cout << "You did not answer! Enter card with correct suit";
		cin >> n;
	}
	while (!is_valid_move()) {
		cout << "New entry: ";
		cin >> n;
	}
	c = hand[n + 1];
	auto it = hand.begin() + n;
	hand.erase(it);
	return c;
}