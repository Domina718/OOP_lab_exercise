#include "z2.hpp"


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
		if (n > a&& n < b)
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


vector <int> newVector(vector<int> v1, vector<int> v2)
{
	vector <int> newvec;
	int n = v1.size(), m = v2.size();
	for (int i = 0; i < n; i++)
	{
		bool flag = true;
		for (int j = 0; j < m; j++)
		{
			if (v1[i] == v2[j])
				flag = false;
		}
		if (flag == true)
			newvec.push_back(v1[i]);
	}
	return newvec;
}