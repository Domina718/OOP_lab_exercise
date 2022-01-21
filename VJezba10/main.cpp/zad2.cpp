#include "zad2.h"
#include <vector>

using namespace std;

template <typename T> bool Stack<T>::isEmpty() {
	return (!v.size());
}

template <typename T> void Stack<T>::push(T n) {
	if (isFull()) {
		cout << "Stack is full!" << endl;
		return;
	}
	this->v.push_back(n);
}

template <typename T> T Stack<T>::pop() {
	if (isEmpty()) {
		cout << "Empty stack" << endl;
		return NULL;
	}

	T* temp = &v.back();
	v.pop_back();

	return *temp;
}

template <typename T> bool Stack<T>::isFull() {
	return (v.size() == maxSize);
}

template <typename T> void Stack<T>::printStack() {
	for (auto n : v)
		cout << n << " ";
	cout << endl;
}