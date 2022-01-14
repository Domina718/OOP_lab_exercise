#include "card.h"

using namespace std;

string card::get_number() const{
	return this->number;
}

string card::get_suit() const{
	return this->suit;
}

//void card::set_value() {
//	if (this->number == "ACE")
//		this->value = 3;
//	else if (this->number = "TWO" || this->number = "THREE")
//		this->value = 0;
//	else
//		this->value = 1;
//}

int card::get_value() const {
	return this->value;
}