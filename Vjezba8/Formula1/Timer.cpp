#include "Timer.hpp"

int Timer:: get_h() const{
	return this->h;
}

int Timer::get_m() const{
	return this->m;
}

double Timer::get_s() const{
	return this->s;
}

void Timer::set_h(int h) {
	this->h = h;
}

void Timer::set_m(int m) {
	this->m = m;
}

void Timer::set_s(double s) {
	this->s = s;
}

Timer::operator double() {
	/*set_s( double(h)* 3600 + double(m) * 60 + s);
	return this->s;*/
	return double(h) * 3600 + double(m) * 60 + s;
}

Timer& operator+=(Timer& s, Timer& a) {
	/*s.set_h(s.get_h() + a.get_h());
	s.set_m(s.get_m() + a.get_m());*/
	s.set_s(s.get_s() + a);
	return s;
}

Timer& operator/=(Timer& s, int size) {
	s.set_s(s.get_s() / size);
	s.set_h(int(s.get_s())/3600);
	s.set_m(int(s.get_s()) % 3600 / 60);
	s.set_s(s.get_s() - s.get_h()*1.0*3600 - s.get_m()*1.0*60);
	return s;
}


ostream& operator<< (ostream& os, const Timer& t) {
	os << t.get_h() << ':' << t.get_m() << ':' << t.get_s();
	return os;
}


Timer& Penalty::operator()(Timer& t){
	t.set_s(t.get_s + ps);
	if (t.get_s() >= 60) {
		t.set_m(t.get_m() + int(t.get_s()) / 60);
		t.set_s(t.get_s() - 60 * int(t.get_s()) / 60);
		if(t.get_m() >= 60){
			t.set_h(t.get_h() + t.get_m() / 60);
			t.set_m(t.get_m() - 60 * t.get_m() / 60);
		}
	}
}