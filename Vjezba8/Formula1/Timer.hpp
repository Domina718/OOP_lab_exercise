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
	Timer& operator+=(const Timer& a);
	Timer& operator-(const Timer& a);
	Timer& operator/=(int size);
	operator double();
	friend ostream& operator<< (ostream& os, const Timer& t);
	int get_h()const;
	int get_m()const;
	double get_s()const;
	bool operator<(const Timer& a);

};

class Penalty {
	double ps;
public:
	Penalty(double s) { ps = s; }
	Timer& operator()(Timer& t);	
};