// Zad6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> reverseSortedStringsInVector()
{
    vector<string> vs;
    string s;
    cout << "Unosite stringove, kad ste gotovi pritisnite CTRL + z" << endl;
    while (getline(cin, s))
    { 
        reverse(s.begin(), s.end());
        vs.push_back(s);
    }
    sort(vs.begin(), vs.end());
    return vs;
}

void printVectorofStrings(vector<string> vs)
{
    int vsize = vs.size();
    for (int i = 0; i < vsize; i++)
        cout << vs[i] << endl;
}

int main()
{
    vector<string> vs = reverseSortedStringsInVector();
    cout << endl;
    printVectorofStrings(vs);
  
}
