#pragma once

#include "deck.h"
#include "player.h"
#include "humanplayer.h"
#include "computerplayer.h"

class game {
	vector<player*> players; //polimorfizam
	deck deck;
	vector<card> on_table;
	void play_turn(int& first, int& second);
public:
	game(string name) { players.push_back(new humanplayer(name)); players.push_back(new computerplayer("Computer"));};
	~game() { players.clear(); };
	void initialize_game(int game_num);
	void play();
	int has_won_hand(vector<card> on_table, int first, int second);
	void has_won_game(int last);
	bool has_won_match();
	void print_score_board()const;
	void check_akuza(int first, int second);
};