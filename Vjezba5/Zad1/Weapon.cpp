#include "Weapon.h"
using namespace std; 

void Weapon::set_p(double x, double y, double z) {
	p.set_point(x, y, z);
}

point Weapon::get_p() const {
	return p;
}

void Weapon::shoot() {
	bullets_current -= 1;
}

void Weapon::reload() {
	bullets_current = 6;
}

int Weapon::get_bullets_current() const {
	return bullets_current;
}