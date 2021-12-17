#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

class Timer {
	int h, m;
	double s;
public:
	Timer() { h = 0; m = 0; s = 0; }
	Timer(int hour, int minute, double second) { h = hour; m = minute; s = second; }
	friend Timer& operator+=(Timer& s, Timer& a);
	friend Timer& operator/=(Timer& s, int size);
	operator double();
	friend ostream& operator<< (ostream& os, const Timer& t);
	int get_h()const;
	int get_m()const;
	double get_s()const;
	void set_h(int h);
	void set_m(int m);
	void set_s(double s);
};

class Penalty {
	double ps;
public:
	Penalty(double s) { ps = s; }
	Timer& operator()(Timer& t);
};