// Zad1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include "point.h"
#include "Weapon.h"
#include "Target.h"
#include "Hits.h"
using namespace std;


int main()
{
	srand(time(NULL));
	point p1;
	point p2;
	p1.set_point(3.7,2.4,-8.23);
	p2.set_random_point(-12,27.3);
	p1.print();
	p2.print();
	cout << "Distance in 2D is " << p1.distance_2D(p2) << endl;
	cout << "Distance in 3D is " << p1.distance_3D(p2) << endl;

	Target* targets;
	Weapon shooter;
	int n = 0;
	targets = generate_targets_and_shooter(shooter, n);
	cout << hits(targets, shooter, n) << " successful hit(s)" << endl;
	
	delete[] targets;


	return 0;

}
