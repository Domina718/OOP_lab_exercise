#pragma once
#include <iostream>
#include <string>
using namespace std;

class card {
	string suit;
	string number;
	int strength;
	int value;
public:
	card() { value = 0; };
	card(string suit, string number, int strength, int value) {
		this->suit = suit;
		this->number = number;
		this->strength = strength;
		this->value = value;
	};

	string get_number() const;
	string get_suit() const;
	int get_value() const;
	int get_strength() const;
	friend ostream& operator<< (ostream& output, const card& c) { output << c.number << " of " << c.suit << endl; return output; };
	bool& operator==(card& c) { 
		bool result = false;

		if (this->suit == c.get_suit() && this->number == c.get_number()) {
			result = true;
		}
		
		return result;
	};
};