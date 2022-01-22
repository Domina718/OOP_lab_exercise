#pragma once
#include <vector>
#include "card.h"

using namespace std;

class player {
protected:
	string name;
	int points;
	vector<card> hand;
	vector<card> won_pile;
public:
	player() { points = 0; };
	void collect_from_table(vector<card> cards);
	void add_points(int last_point);
	int score() const;
	void set_hand(vector<card> hand);
	void draw_card(card& c);
    void show_hand() const;
	string get_name()const;
	void reset_won_pile();
	virtual card play_card() = 0;
	virtual card play_card(card& c) = 0;
	
};