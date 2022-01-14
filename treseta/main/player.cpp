#include "player.h"
#include <iostream>

using namespace std;

void player::add_points(int points) {
	this->points += points;
}

int player::score() const{
	return this->points;
}

void player::set_hand(vector<card> hand) {
	this->hand = hand;
}

void player::show_hand() const{
	for (auto c : hand)
		cout << &c;
}
