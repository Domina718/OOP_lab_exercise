// Zad3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printVector(vector <int> v)
{
	int n = v.size();
	for (int i = 0; i < n; i++)
		cout << v[i] << "  ";
	cout << endl;
}


int main()
{
	vector<int> v{ 3, 6, 23, 7, 24, 14, 7, 29 };
	sort(v.begin(), v.end());
	v.insert(v.begin(), 0);
	int sum = 0, size = v.size();
	for (int i = 0; i < size; i++)
		sum += v[i];
	v.push_back(sum);

	printVector(v);


}
