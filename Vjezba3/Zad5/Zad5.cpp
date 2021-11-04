// Zad5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int cntRepeat(string s1, string s2)
{
    int size = s1.size(), cnt = 0;
    size_t f = -1;
    for (int i = 0; i < size; i++)
    {
        f = s1.find(s2, i-1);
        if (f != -1)
        {
            cnt++;
            i += s2.size();
            f = -1;
        }
    }
    return cnt;
}



int main()
{
    string s = { "abbababbababa" }, ps = { "aba" };
    cout <<"'" << ps << "'" << " se ponavlja " << cntRepeat(s, ps) << " puta u " << "'" << s << "'" << endl;
}
