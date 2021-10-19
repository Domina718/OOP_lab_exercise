// Zad3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

int mini (int *arr, int size)
{
	int min = *arr;
	for (int i = 1; i < size; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	return min;
}

int maxi (int *arr, int size)
{
	int max = *arr;
	for (int i = 1; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;

}

int main()
{
	int arr[] = {2,5,9,7,11,28};
	int min = mini (arr, sizeof(arr)/sizeof(arr[0]));
	int max = maxi (arr, sizeof(arr)/sizeof(arr[0]));
	cout << "min je " << min << endl;
	cout << "max je " << max << endl;
}
