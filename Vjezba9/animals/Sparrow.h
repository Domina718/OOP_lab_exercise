#pragma once
#include "Bird.h"

class Sparrow : public Bird {
public:
	Sparrow() { this->name = "Sparrow"; this->numOfLegs = 2; }
	int getLegs();
	string getName();
};