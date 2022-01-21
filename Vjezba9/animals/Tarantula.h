#pragma once
#include "Spider.h"

class Tarantula : public Spider {
public: 
	Tarantula() { this->name = "Tarantula"; this->numOfLegs = 8; };
	int getLegs();
	string getName();
};