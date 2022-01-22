#include "game.h"
#include <iostream>

using namespace std;


void game::initialize_game() {
	deck.initialize_deck();
	deck.shuffle();
	/*cout << "Deck" << endl;
	deck.print_deck();*/
	for (auto player : players) {
		player->set_hand(deck.deal());
		player->reset_won_pile();
	}
}

int game::has_won_hand(vector<card> cards, int first, int second) {
	if (cards[0].get_suit() != cards[1].get_suit())
		return first;
	if (cards[0].get_strength() > cards[1].get_strength())
		return first;
	return second;
}

void game::has_won_game(int last) {
	if (last == 0) {
		players[0]->add_points(1);
		players[1]->add_points(0);
		return;
	}
	players[0]->add_points(0);
	players[1]->add_points(1);
}

bool game::has_won_match() {
	for(auto player : players)
	if (player->score() >= 21) {
		cout << player->get_name() << " won!" << endl;
		return true;
	}
	return false;
}

void game::play_turn(int &first, int &second) {
	on_table.push_back(players[first]->play_card());
	on_table.push_back(players[second]->play_card(on_table[0]));
	first = has_won_hand(on_table, first, second);
	second = 1 - first;
	players[first]->collect_from_table(on_table);
	on_table.clear();
	cout << players[first]->get_name() << " won hand\n" << endl;
}

void game::play() {
	int game_num = 1;
	int first, second;
	while (!has_won_match()) {
		initialize_game();
		if (game_num % 2 == 1) {
			first = 0;
			second = 1;
		}
		else {
			first = 1; 
			second = 0;
		}
		while (!deck.is_empty()) {
			play_turn(first, second);
			for (auto player : players) {
				card new_card = deck.draw();
				player->draw_card(new_card);
				cout << player->get_name() << " draws " << new_card << endl;
			}
		}
		for (int i = 0; i < 10; i++) {
			play_turn(first, second);
		}
		has_won_game(first);
		game_num++;
	}
}