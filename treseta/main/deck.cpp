#include "deck.h"
#include "card.h"
#include <iostream>
#include <time.h>
#include <algorithm>

using namespace std;


deck::deck() {
	string card_suits[] = { "SWORDS", "CUPS", "COINS", "CLUBS" };
	string card_numbers[] = { "ACE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "KNAVE", "KNIGHT", "KING" };
	for (auto s : card_suits) {
		for (auto n : card_numbers) {
			if (n == "ACE") {
				d.push_back(card(s, n, 3));
			}
			else if (n == "TWO" || n == "THREE" || n == "KNAVE" || n == "KNIGHT" || n == "KING") {
				d.push_back(card(s, n, 1));
			}
			else {
				d.push_back(card(s, n, 0));
			}
		}
	}
}

void deck::print_deck() const{
	for (auto c : this->d)
		cout << c.get_number() << " of " << c.get_suit() << " point: " << c.get_value() << endl;
}

void deck::shuffle() {

	random_shuffle(d.begin(), d.end());
}

card deck::draw() {
	card c = d.back();
	d.pop_back();
	return c;
}

bool deck::is_empty() {
	return !d.size();
}

vector<card> deck::deal() {
	vector<card> cards;
	for (int i = 0; i < 10; i++) {
		cards.push_back(d.back());
		d.pop_back();
	}
	return cards;
}