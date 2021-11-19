#include "Target.h"
using namespace std;


void Target::set_point_a(double x, double y, double z) {
	a.set_point(x, y, z);
}

void Target::set_point_g(double x, double y, double z) {
	g.set_point(x, y, z);
}

point Target::get_point_a() const{
	return a;
}

point Target::get_point_g() const{
	return g;
}

void Target::is_it_hit() {
	hit = true;
	cout << "Hit!" << endl;
}