#include "player.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void player::add_points(int last_point) {
	int points = 0;

	for (auto card : won_pile) {
		points += card.get_value();
	}

	points /= 3;
	points += last_point;
	cout << this->name << " won " << points << " points." << endl;

	this->points += points;
}

int player::score() const {
	return this->points;
}

void player::set_hand(vector<card> hand) {
	this->hand = hand;
}

void player::show_hand() const {
	int cnt = 1;

	for (auto c : hand) {
		cout << "(" << cnt << ") " << c;
		cnt++;
	}
}

void player::collect_from_table(vector<card> cards) {
	for (auto card : cards)
		this->won_pile.push_back(card);

}

void player::draw_card(card& c) {
	this->hand.push_back(c);
}


string player::get_name()const {
	return this->name;
}

void player::reset_won_pile() {
	this->won_pile.clear();
}

void player::akuza() {
	vector<vector<card>> counters(7); // napolitana cups, napolitana swords, napolitana coins, napolitana clubs, Aces, Twos, Threes
	string card_suits[] = { "CUPS", "SWORDS", "COINS", "CLUBS" };
	
	for (auto card : hand) {
		for (int i = 0; i < 4; i++) {
			if (card.get_number() == "ACE" && card.get_suit() == card_suits[i]) {
				counters[i].push_back(card);
				counters[4].push_back(card);
			}
			else if (card.get_number() == "TWO" && card.get_suit() == card_suits[i]) {
				counters[i].push_back(card);
				counters[5].push_back(card);
			}
			else if (card.get_number() == "THREE" && card.get_suit() == card_suits[i]) {
				counters[i].push_back(card);
				counters[6].push_back(card);
			}
		}
	}

	for (int i = 0; i < 7; i++) {
		if (counters[i].size() >= 3) {
			switch (i) {
			case 0: cout <<"\n" << this->name << " has napolitana of cups\n" << endl;
				this->points += 3;
				break;
			case 1: cout <<"\n" << this->name << " has napolitana of swords\n" << endl;
				this->points += 3;
				break;
			case 2: cout <<"\n" << this->name << " has napolitana of coins\n" << endl;
				this->points += 3;
				break;
			case 3: cout << "\n" << this->name << " has napolitana of clubs\n" << endl;
				this->points += 3;
				break;
			case 4: if (counters[4].size() == 4) {
					cout << "\n" << this->name << " has all four Aces\n" << endl;
					this->points += 4;
					}
					else {
						string missing_suit;
						bool flag;
						for (auto suit : card_suits) {
							flag = false;
							for (auto card : counters[4]) {
								if (card.get_suit() == suit) {
									flag = true;
								}
							}
							if (flag == false) {
								missing_suit = suit;
								break;
							}
						}
						cout << "\n" << this->name << " has three Aces without the Ace of "  << missing_suit << "\n"<< endl;
						this->points += 3;
					}
				break;
			case 5: if (counters[5].size() == 4) {
					cout << "\n" << this->name << " has all four Twos\n" << endl;
					this->points += 4;
					}
					else {
						string missing_suit;
						bool flag;
						for (auto suit : card_suits) {
							flag = false;
							for (auto card : counters[4]) {
								if (card.get_suit() == suit) {
									flag = true;
								}
							}
							if (flag == false) {
								missing_suit = suit;
								break;
							}
						}
					cout << "\n" << this->name << " has three Twos without the Two of " << missing_suit << "\n" << endl;
					this->points += 3;
					}
				  break;
			case 6: if (counters[4].size() == 4) {
					cout << "\n" << this->name << " has all four Threes\n" << endl;
					this->points += 4;
					}
					else {
						string missing_suit;
						bool flag;
						for (auto suit : card_suits) {
							flag = false;
							for (auto card : counters[4]) {
								if (card.get_suit() == suit) {
									flag = true;
								}
							}
							if (flag == false) {
								missing_suit = suit;
								break;
							}
						}
						cout << "\n" << this->name << " has three Threes without the Three of " << missing_suit << "\n" << endl;
						this->points += 3;
					}
				  break;
			}
		}
	}
}
