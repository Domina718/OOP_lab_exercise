// Zad2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

int& vrati(int* arr, int i)
{
	return arr[i];

}

void main()
{
	int arr[] = { 5,4,3,2,-5,7,12 };
	vrati(arr, 3) ++;
	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
		cout << arr[i] << endl;

}

