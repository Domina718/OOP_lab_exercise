#pragma once
#include <string>

using namespace std;

class Player {
protected:
	int points;
	string name;
	int hand;
public:
	virtual void chooseCoins() {};
	virtual int guessSum() { return 1; };
	string getName();
	void addPoint();
	int getPoints();
	int getHand();
	void resetHand();

};