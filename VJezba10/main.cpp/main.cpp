#include <iostream>
#include "zad1.h"
#include "zad2.h"
#include "zad2.cpp"

using namespace std;

int main()
{
    int a[] = { 7,2,3,1,4 };
    double d[] = { -2.13, 4, -5.173, 12.01 };
    sorting(a, 5);
    print(a, 5);

    unsigned char c[] = { 'a', 'C', 'b', 'H' };
    cout << toupper('c') << endl;
    sorting(c, 4);
    print(c, 4);

    //sort(d, 4);
    //print(d, 4);

    //zad2: Stack

    Stack<int> s;
    cout << "1st print  ";
    cout << s.pop() << endl;
    s.printStack();
    s.push(13);
    s.push(-3);
    s.push(34);
    s.push(64576);
    s.push(17);
    s.push(1);
    s.printStack();

    auto n = s.pop();
    cout << n  << endl;
    s.printStack();

    cout << s.pop() << endl;
    s.printStack();



    return 0;
}