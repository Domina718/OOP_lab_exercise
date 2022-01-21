#pragma once
#include <string>
#include <iostream>

using namespace std;

class Animal {
protected:
	string name;
	int numOfLegs;
public:
	virtual int getLegs() = 0;
	virtual string getName() = 0;
};
