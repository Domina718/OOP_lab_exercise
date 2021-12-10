#include "connectFour.hpp"

int min(int a, int b) {
	if (a > b)
		return b;
	return a;
}

int max(int a, int b) {
	if (a > b)
		return a;
	return b;
}

Point::Point(double a, double b) {
	x = a;
	y = b;
}

Board::Board() { 
	c = 'o'; 
	this->x = 20;
	this->y = 10;
	matrix = new char*[y]; 
	for (int i = 0; i < y; i++) { 
		matrix[i] = new char[x]; 
	} 

	for (int j = 0; j < x; j++) {
		matrix[0][j] = c;
	}
	for (int i = 1; i < y - 1; i++) {
		for (int j = 0; j < x; j++)
		{
			if (j == 0 || j == x - 1)
				matrix[i][j] = c;
			else
				matrix[i][j] = ' ';
		}
	}
	int i = y - 1;
	for (int j = 0; j < x; j++) {
		matrix[i][j] = c;
	}
}

Board::Board(double x, double y) {
	char c = 'o';
	this->y = round(y);
	this->x = round(x);
	matrix = new char* [y];
	for (int i = 0; i < y; i++) {
		matrix[i] = new char[x];
	}
	for (int j = 0; j < x; j++) {
		matrix[0][j] = c;
	}
	for (int i = 1; i < y - 1; i++) {
		for (int j = 0; j < x; j++)
		{
			if (j == 0 || j == x - 1)
				matrix[i][j] = c;
			else
				matrix[i][j] = ' ';
		}
	}
	int i = y - 1;
	for (int j = 0; j < x; j++) {
		matrix[i][j] = c;
	}
}

Board::Board(const Board& other) { 
	c = other.c; 
	int y = round(other.y);
	int x = round(other.x);
	matrix = new char* [y]; 
	for (int i = 0; i < y; i++)
		matrix[i] = new char[x];
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++)
		{
			matrix[i][j] = other.matrix[i][j];
		}
	}

}

Board::Board( Board&& other) { 
	c = other.c; 
	int y = round(other.y);
	int x = round(other.x);
	matrix = new char* [y];
	for (int i = 0; i < y; i++)
		matrix[i] = new char[x];
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++)
		{
			matrix[i][j] = other.matrix[i][j];
		}
	}
	for (int i = 0; i < round(y); i++) { 
		delete[]other.matrix[i]; 
	} 
	delete[]other.matrix;
	// other.matrix = nullptr;
	other.c = NULL;
	other.x = NULL;
	other.y = NULL;


}

//void Point::set_x(double x) {
//	this->x = round(x);
//}
//
//void Point::set_y(double y) {
//	this->y = round(y);
//}
//
//double Point::get_x() const {
//	return this->x;
//}
//
//double Point::get_y() const {
//	return this->y;
//}

void Board::draw_char(Point p, char c) {
	int x = round(p.x);
	int y = round(p.y);
	matrix[x][y] = c;
}

void Board::draw_up_line(Point p1, char c) {
	int j = p1.x;
	for (int i = p1.y; i > 0; i--) {
		matrix[i][j] = c;
	}
	return;
}

void Board::draw_line(Point p1, Point p2, char c) {
	if (p1.x > x - 1 || p1.y > y - 1 || !p1.x || !p1.y) {
		cout << "Point 1 is out of matrix dimensions" << endl;
		return;
	}
	if (p2.x > x - 1 || p2.y > y - 1 || !p2.x || !p2.y) {
		cout << "Point 2 is out of matrix dimensions" << endl;
		return;
	}
	if (p1.x == p2.x) {
		int j = p1.x;
		int mini = min(round(p1.y), round(p2.y));
		int maxi = max(round(p1.y), round(p2.y));
		for (int i = mini; i < maxi; i++) {
			matrix[i][j] = c;
		}
		return;
	}
	if (p1.y == p2.y) {
		int j = p1.y;
		int mini = min(round(p1.x), round(p2.x));
		int maxi = max(round(p1.x), round(p2.x));
		for (int i = mini; i < maxi; i++) {
			matrix[j][i] = c;
		}
		return;
	}
	if ((p1.x - p1.y) == (p2.x - p2.y)) {
		int mini_x = min(round(p1.x), round(p2.x));
		int maxi_x = max(round(p1.x), round(p2.x));
		int mini_y = min(round(p1.y), round(p2.y));
		int maxi_y = max(round(p1.y), round(p2.y));
		for (int i = mini_y, j = mini_x ; i < maxi_y;j++, i++) {
				matrix[i][j] = c;
		}
		return;
	}
	cout << "Line can't be drawn between these points" << endl;
	return;
}

void Board::display() {

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++)
		{
			cout << matrix[i][j];
		}
		cout << endl;
	}
}

