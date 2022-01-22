#include "card.h"

using namespace std;

string card::get_number() const{
	return this->number;
}

string card::get_suit() const{
	return this->suit;
}

int card::get_value() const {
	return this->value;
}

int card::get_strength() const {
	return this->strength;
}