#pragma once
#include "Insect.h"

class Cockroach : public Insect {
public:
	Cockroach() { this->name = "Cockroach"; this->numOfLegs = 6; };
	int getLegs();
	string getName();
};