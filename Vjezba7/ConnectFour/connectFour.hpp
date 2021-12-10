#pragma once
#include <iostream>
using namespace std;

typedef struct Point {
	double x;
	double y;
	Point(double a, double b);
//public:
//	Point(double a, double b) { x = a; y = b; }
//	void set_x(double x);
//	void set_y(double y);
//	double get_x() const;
//	double get_y() const;
}Point;



class Board {
	double x, y;
	char** matrix;
	char c;
public:
	Board();
	Board(double x, double y);
	Board(const Board& other); 
	Board(Board&& other); 
	~Board() { for (int i = 0; i < round(y); i++) { delete[]matrix[i]; } delete[]matrix; };
	void draw_char(Point p, char c);
	void draw_up_line(Point p1, char c);
	void draw_line(Point p1, Point p2, char c);
	void display();
};

