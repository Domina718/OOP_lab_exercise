#pragma once
#include "player.h"

class computerplayer : public player {
public:
	card play_card(int turn, card playedCard);

};