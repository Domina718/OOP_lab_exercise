#include "z1.hpp"



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


void inputVectorInterval(vector <int>& v, int a, int b)
{
	int n;
	while (1)
	{
		cout << "\nNovi broj:  ";
		cin >> n;
		if (n > a && n < b)
			v.push_back(n);
		else
			break;
	}
}

void printVector(vector <int> v)
{
	int n = v.size();
	for (int i = 0; i < n; i++)
		cout << v[i] << "  ";
	cout << endl;
}