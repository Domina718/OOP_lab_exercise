#pragma once
#include "point.h"

class Weapon {
	point p;
	int bullets_total;
	int bullets_current;
public:
	void set_p(double x, double y, double z);
	point get_p() const;
	Weapon() {bullets_total = 6; bullets_current = 6;};
	void shoot();
	void reload();
	int get_bullets_current() const;
};