#pragma once
#include "zad1.h"
#include <iostream>
#include <cctype>

using namespace std;

template <class T>
void swapTwo(T& a, T& b) {
	T t = a;
	a = b;
	b = t;
}

template<typename T>
void sorting(T* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i; j < n ; j++) {
			if (arr[i] > arr[j])
				swapTwo(arr[i], arr[j]);
		}
	}
}

//template <> 
//void sort<unsigned char>(unsigned char& arr, int n) {
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = i; j < n; j++) {
//			if (tolower(arr + i) > tolower(arr + j))
//				swapTwo<unsigned char>(arr[i], arr[j]);
//		}
//	}
//}

//bool cmp(const char a, const char b){
//	return tolower(a) < tolower(b);
//}
//
//template<>
//void sorting(unsigned char* arr, int n) {
//	sort(arr, arr + n, cmp);
//}

template <>
void sorting(unsigned char* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i; j < n; j++) {
			if (toupper(arr[i]) > toupper(arr[j]))
				swapTwo(arr[i], arr[j]);
		}
	}
}


template<typename T>
void print(T& arr, int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}


