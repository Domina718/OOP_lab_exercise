// Zad4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


using namespace std;

int maxi(int *arr, int size, int max)
{
    if (size == 1)
        return max;
    if (max < arr[size-1])
        max = arr[size-1];
    return maxi (arr, size - 1, max);
}

int mini(int* arr, int size, int min)
{
    if (size == 1)
        return min;
    if (min > arr[size - 1])
        min = arr[size - 1];
    return mini(arr, size - 1, min);
}

int main()
{
    int arr[] = { -3, 5, -16, 24, 0, 9 };
    int max = maxi(arr, sizeof(arr) / sizeof(arr[0]) - 1, arr[sizeof(arr) / sizeof(arr[0])-1]);
    cout << "najveci je " << max << endl;
    int min = mini(arr, sizeof(arr) / sizeof(arr[0]) - 1, arr[sizeof(arr) / sizeof(arr[0]) - 1]);
    cout << "najmanji je " << min << endl;

}
