// Zad1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

void minMaxByReference(int *arr, int &a, int &b, int size)
{
	a = b = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (arr[i] < a)
			a = arr[i];
		if (arr[i] > b)
			b = arr[i];
	}

}


void main()
{
	int min, max, arr[] = {1,2,3,4,9,-5,0,-25,13,2};
	minMaxByReference(arr, min, max, sizeof(arr)/sizeof(arr[0]));
	cout << "Min je " << min << ", a max je " << max << endl;

}