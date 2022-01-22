#include "deck.h"
#include "card.h"
#include <iostream>
#include <time.h>
#include <algorithm>

using namespace std;


void deck::initialize_deck() {
	string card_suits[] = { "SWORDS", "CUPS", "COINS", "CLUBS" };
	string card_numbers[] = { "ACE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "KNAVE", "KNIGHT", "KING" };
	for (auto s : card_suits) {
		for (auto n : card_numbers) {
			if (n == "ACE") {
				d.push_back(card(s, n, 8, 3));
			}
			else if (n == "TWO") {
				d.push_back(card(s, n, 9, 1));
			}
			else if (n == "THREE") {
				d.push_back(card(s, n, 10, 1));
			}
			else if (n == "KNAVE") {
				d.push_back(card(s, n, 5, 1));
			}
			else if (n == "KNIGHT") {
				d.push_back(card(s, n, 6, 1));
			}
			else if(n == "KING") {
				d.push_back(card(s, n, 7, 1));
			}
			else if(n == "SEVEN"){
				d.push_back(card(s, n, 4, 0));
			}
			else if (n == "SIX") {
				d.push_back(card(s, n, 3, 0));
			}
			else if (n == "FIVE") {
				d.push_back(card(s, n, 2, 0));
			}
			else {
				d.push_back(card(s, n, 1, 0));
			}
		}
	}
}

void deck::print_deck() const{
	for (auto c : this->d)
		cout << c;
		
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