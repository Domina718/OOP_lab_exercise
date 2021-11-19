#pragma once
#include "point.h"


class Target {
	point a;
	point g;
	bool hit;
public:
	Target() { hit = false; }
	void set_point_a(double x, double y, double z);
	void set_point_g(double x, double y, double z);
	point get_point_a() const;
	point get_point_g() const;
	void is_it_hit();
};