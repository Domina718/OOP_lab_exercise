#pragma once
#include "player.h"

class computerplayer : public player {
public:
	computerplayer(string name) { this->name = name; };
	card play_card(card &playedCard);
	card play_card();
};