#include "computerplayer.h"

card computerplayer::play_card(card &playedCard) {
	int cnt = 0;

	for (auto c : this->hand) {
		if(c.get_suit() == playedCard.get_suit()){
			c = hand[cnt];
			cout << this->name << " played in second turn " << c << endl;
			auto it = hand.begin() + cnt;
			hand.erase(it);
			return c;
		}
		cnt++;	
	}

	card c = hand[0];
	cout << this->name << " played in second turn " << c << endl;
	auto it = hand.begin();
	hand.erase(it);

	return c;
}

card computerplayer::play_card() {
	card c = hand[0];
	cout <<"\n" << this->name << " played " << c << endl;
	auto it = hand.begin();
	hand.erase(it);

	return c;
}