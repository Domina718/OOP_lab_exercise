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
	void initialize_game();
	void play();
	int has_won_hand(vector<card> on_table, int first, int second);
	void has_won_game(int last);
	bool has_won_match();
	
};