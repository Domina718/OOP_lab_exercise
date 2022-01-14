#pragma once
#include <iostream>
#include <string>
using namespace std;

class card {
	string suit;
	string number;
	int value;
public:
	card() {};
	card(string suit, string number, int value) {
		this->suit = suit;
		this->number = number;
		this->value = value;
	};

	string get_number() const;
	string get_suit() const;
	int get_value() const;
	ostream& operator<< (card& c) { cout << number << " of " << suit << endl; };
	bool& operator==(card& c) { 
		bool result = false;

		if (this->suit == c.get_suit() && this->number == c.get_number()) {
			result = true;
		}
		
		return result;
	};
};