#pragma once
#include <vector>
#include "card.h"

using namespace std;

class deck {
	vector<card> d;
public:
	deck();
	void shuffle();
	card draw();
	bool is_empty();
	void print_deck() const;
	vector<card> deal();
};