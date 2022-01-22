#pragma once
#include "player.h"

class humanplayer : public player {
public:
	humanplayer(string name) { this->name = name; };
	card play_card();
	card play_card(card &card_played);
	bool is_valid_move(card card_played, int n);
};
