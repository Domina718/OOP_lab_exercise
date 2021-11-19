#pragma once
#include <cmath>
#include <iostream>
#include <random>


class point {
	double x;
	double y;
	double z;
public:
	point() { x = 0; y = 0; z = 0;}
	void set_point(double x, double y, double z);
	void set_random_point(double a, double b);
	void get_point() const;
	double get_z() const;
	void print() const;
	double distance_2D(point& p) const;
	double distance_3D(point& p) const;
};


