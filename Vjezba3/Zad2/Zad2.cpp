// Zad2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "z2.hpp"

int main()
{
	vector <int> v1, v2, v3;
	inputVector(v1, 4);
	inputVector(v2, 8);

	v3 = newVector(v1, v2);

	printVector(v3);
}
