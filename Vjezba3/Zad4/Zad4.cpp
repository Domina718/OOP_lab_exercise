// Zad4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;


void inputVector(vector <int>& v, int n)
{
	int e;
	for (int i = 0; i < n; i++)
	{
		cout << "\nUnesite " << i + 1 << ". element ";
		cin >> e;
		v.push_back(e);
	}
}

void removeElement(vector<int>& v)
{
	int n;
	cout << "\nUnesite poziciju elementa kojeg zelite ukloniti  ";
	cin >> n;

	v.erase(v.begin() + n - 1);
	v.insert(v.begin() + n, *(v.end() - 1));
	v.pop_back();
}

void printVector(vector <int> v)
{
	int n = v.size();
	for (int i = 0; i < n; i++)
		cout << v[i] << "  ";
	cout << endl;
}



int main()
{
	vector<int> v;
	inputVector(v, 7);
	//cout << "\nVelicina vektora je " << v.size() << endl;

	removeElement(v);

	//cout << "\nVelicina vektora je " << v.size()<< endl;

	printVector(v);


}
	