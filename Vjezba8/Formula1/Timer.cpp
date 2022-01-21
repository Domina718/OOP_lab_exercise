#include "Timer.hpp"
#include <algorithm>

int Timer:: get_h() const{
	return this->h;
}

int Timer::get_m() const{
	return this->m;
}

double Timer::get_s() const{
	return this->s;
}


Timer::operator double() {

	return double(this->h) * 3600 + double(this->m) * 60 + this->s;
}

Timer& Timer::operator+=(const Timer& a) {

	this->s += a.get_h() * 3600 + a.get_m() * 60 + a.get_s();
	return *this;
}

Timer& Timer::operator-(const Timer& a) {

	this->s = this->s - a.get_s();
	this->m = this->m - a.get_m();
	this->h = this->h - a.get_h();
	return *this;
}

Timer& Timer::operator/=(int size) {

	this->s /= size;
	this->h = this->s / 3600;
	this->m = (this->s - this->h*3600) / 60;
	this->s = this->s - this->h*3600 - this->m*60;

	return *this;
}


ostream& operator<< (ostream& os, const Timer& t) {

	os << t.get_h() << ':' << t.get_m() << ':' << t.get_s();
	return os;
}

bool Timer::operator<(const Timer& a) {

	return double(*this) < (a.get_h() * 3600 + a.get_m() * 60 + a.get_s());
}


Timer& Penalty::operator()(Timer& t) {
	
	Timer p = Timer(0, 0, ps);
	t +=p;
	return t;
}