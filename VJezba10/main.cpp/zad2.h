#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <typename T> 
class Stack {
	vector<T> v;
	int maxSize;
public:
	Stack() { maxSize = 1024; };
	bool isEmpty();
	void push(T n);
	T pop();
	bool isFull();
	void printStack();
};