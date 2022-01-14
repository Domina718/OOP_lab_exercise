#pragma once
#include <vector>
#include "card.h"

using namespace std;

class player {
protected:
	int points;
	vector<card> hand;
public:
	player() { points = 0; };
	void add_points(int points);
	int score() const;
	void set_hand(vector<card> hand);
    void show_hand() const;
	virtual card play_card();
};