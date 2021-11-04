// Zad3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>

using namespace std;

struct Point {
    float x;
    float y;
};

struct Circle {
    Point s;
    float r;
};

struct Rectangle {
    Point a;
    Point c;
};


bool doTheyIntersectPrecious(const Rectangle rectangle, const Circle circle) {

        int Xn = max(rectangle.a.x, min(circle.s.x, rectangle.c.x));
        int Yn = max(rectangle.a.y, min(circle.s.y, rectangle.c.y));

        int Dx = Xn - circle.s.x;
        int Dy = Yn - circle.s.y;

        return (Dx * Dx + Dy * Dy) <= circle.r * circle.r;
}


int intersect(const Rectangle* rectangles, int len, const Circle& circle) {
    
    int cnt = 0;
    for (int i = 0; i < len; i++)
    {
        if (doTheyIntersectPrecious(rectangles[i], circle))
            cnt++;
    }
    return cnt;  
}

int main()
{ 
    Rectangle rect[3];
    rect[0].a.x = 3;
    rect[0].a.y = 2;
    rect[0].c.x = -1;
    rect[0].c.y = 5;

    rect[1].a.x = 5;
    rect[1].a.y = 1;
    rect[1].c.x = 4;
    rect[1].c.x = 3;

    rect[2].a.x = -2;
    rect[2].a.y = -2;
    rect[2].c.x = 0;
    rect[2].c.y = 5;

    Circle circ;
    circ.r = 3.1;
    circ.s.x = 6;
    circ.s.y = 2;

    int cnt = intersect(rect, 3, circ);
    cout << "Ima ih " << cnt << " sta se sijeku" << endl;
    
}

