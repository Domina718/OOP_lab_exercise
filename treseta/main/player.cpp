#include "player.h"
#include <iostream>

using namespace std;

void player::add_points(int last_point) {
	int points = 0;
	for (auto card : won_pile) {
		points += card.get_value();
	}
	cout << this->name << "   Points: " << points << endl;
	points /= 3;
	cout << "\n" << points << endl;
	points += last_point;
	cout << this->name << " won " << points << " points." << endl;
	this->points += points;
}

int player::score() const{
	return this->points;
}

void player::set_hand(vector<card> hand) {
	this->hand = hand;
}

void player::show_hand() const{
	int cnt = 1;
	for (auto c : hand) {
		cout << "(" << cnt << ") " << c;
		cnt++;
	}
}

void player::collect_from_table(vector<card> cards) {
	for(auto card : cards)
		this->won_pile.push_back(card);
	
}

void player::draw_card(card& c) {
	this->hand.push_back(c);
}


string player::get_name()const {
	return this->name;
}

void player::reset_won_pile() {
	this->won_pile.clear();
}