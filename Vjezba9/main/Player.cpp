#include "Player.h"
#include <iostream>


void Player::addPoint() {
	this->points += 1;
}

int Player::getPoints() {
	return this->points;
}

int Player::getHand() {
	return this->hand;
}

string Player::getName() {
	return this->name;
}

void Player::resetHand() {
	this->hand = 0;
}