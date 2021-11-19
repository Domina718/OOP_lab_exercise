#include "Hits.h"
using namespace std;

double min(double a, double b) {
	if (a < b)
		return a;
	return b;
}

double max(double a, double b) {
	if (a > b)
		return a;
	return b;
}

void return_coordinates(double& x, double& y, double& z) {
	cout << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;
	cout << "z = ";
	cin >> z;
}

Target* generate_targets_and_shooter(Weapon& shooter, int &n) {
	cout << "How many targets? ";
	cin >> n;
	cout << endl;
	Target* targets = new Target[n];
	double x, y, z;
	
	for (int i = 0; i < n; i++)
	{
		cout << i+1 <<". target\nEnter coordinates for point a: " << endl;
		return_coordinates(x, y, z);
		targets[i].set_point_a(x, y, z);
		cout << "Enter coordinates for point g: " << endl;
		return_coordinates(x, y, z);
		targets[i].set_point_g(x, y, z);
	}
	cout << "Enter coordinates for the shooter: " << endl;
	return_coordinates(x, y, z);
	shooter.set_p(x, y, z);
	return targets;
}

int hits(Target* targets, Weapon shooter, int n) {
	int h = 0;
	for(int i = 0; i < n; i++)
	{
		if (!shooter.get_bullets_current())
		{
			cout << "Empty clip! Reload pls" << endl;
			break;
		}
		if (max(targets[i].get_point_a().get_z(), targets[i].get_point_g().get_z()) >= shooter.get_p().get_z()
			&& min(targets[i].get_point_a().get_z(), targets[i].get_point_g().get_z()) <= shooter.get_p().get_z())
		{
			h++;
			targets[i].is_it_hit();
		}
		else
			cout << "Miss!" << endl;
		shooter.shoot();
		
	}

	return h;
}