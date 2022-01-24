#include "game.h"
#include <iostream>

using namespace std;

void game::initialize_game(int game_num) {
	deck.initialize_deck();
	deck.shuffle();

	if (game_num % 2 == 1) {
		for (auto player : players) {
			player->set_hand(deck.deal());
			player->reset_won_pile();
		}
	}
	else {
		players[1]->set_hand(deck.deal());
		players[0]->set_hand(deck.deal());

		for (auto player : players) {
			player->reset_won_pile();
		}
	}
	cout << "\nStarting game number " << game_num << endl;
}

void game::check_akuza(int first, int second) {
	players[first]->akuza();
	players[second]->akuza();
	
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

void game::print_score_board()const {
	cout << "\n\nScore board: \n" << endl;

	for (auto player : players) {
		cout << player->get_name() << "---> " << player->score() << " points" << endl;
	}
}

bool game::has_won_match() {
	for (auto player : players) {
		if (player->score() >= 21) {
			cout << player->get_name() << " won!" << endl;
			return true;
		}
	}

	return false;
}

void game::play_turn(int& first, int& second) {
	on_table.push_back(players[first]->play_card());
	on_table.push_back(players[second]->play_card(on_table[0]));

	first = has_won_hand(on_table, first, second);
	second = 1 - first;

	players[first]->collect_from_table(on_table);
	on_table.clear();

	cout <<"\n" << players[first]->get_name() << " won hand\n\n" << endl;
}

void game::play() {
	int game_num = 1;
	int first, second;
	card new_card;

	while (!has_won_match()) {
		initialize_game(game_num);
		
		if (game_num % 2 == 1) {
			first = 0;
			second = 1;
		}
		else {
			first = 1;
			second = 0;
		}

		check_akuza(first, second);

		while (!deck.is_empty()) {
			play_turn(first, second);
			
			new_card = deck.draw();
			players[first]->draw_card(new_card);
			cout << players[first]->get_name() << " draws " << new_card << endl;

			new_card = deck.draw();
			players[second]->draw_card(new_card);
			cout << players[second]->get_name() << " draws " << new_card << endl;
		}

		for (int i = 0; i < 10; i++) {
			play_turn(first, second);
		}

		has_won_game(first);
		print_score_board();

		game_num++;
	}
	print_score_board();
}