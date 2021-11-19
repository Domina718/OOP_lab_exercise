#include "point.h"
using namespace std;

void point::set_point(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

void point::set_random_point(double a, double b) {
	x = a + rand() % int(b-a + 1);
	y = a + rand() % int(b-a + 1);
	z = a + rand() % int(b-a + 1);
}

void point::get_point() const {
	print();
}

double point::get_z() const {
	return this->z;
}

void point::print() const {
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "z = " << z << endl;
}

double point::distance_2D(point& p) const {
	return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2) * 1.0); 
}

double point::distance_3D(point& p) const {
	return sqrt(pow(this->x - p.x, 2) + pow(this->y - p.y, 2) + pow(this->z - p.z, 2) * 1.0);
}