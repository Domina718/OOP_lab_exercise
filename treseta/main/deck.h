#pragma once
#include <vector>
#include "card.h"

using namespace std;

class deck {
	vector<card> d;
public:
	void initialize_deck();
	void shuffle();
	card draw();
	bool is_empty()const;
	void print_deck() const;
	vector<card> deal();
};