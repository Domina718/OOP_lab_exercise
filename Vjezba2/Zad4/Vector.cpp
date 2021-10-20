#include "vector.h"

void MyVector::vector_new(size_t sz)
{
    size = sz;
    capacity = 10;
    arr = new int[capacity];    
}
void MyVector::vector_delete()
{
    delete[] arr;
}
void MyVector::vector_push_back(int n)
{
    int* arr1 = NULL;
    if (size == capacity) {
        capacity += capacity;
        arr1 = new int[capacity];
        for (int i = 0; i < size; i++)
        {
            arr1[i] = arr[i];
        }
        delete[] arr;
        arr = arr1;

    }
    arr[size] = n;
    size++;
}
void MyVector::vector_pop_back()
{
    int* arr1;
    if (size == capacity/2) {
        capacity /= 2;
        arr1 = new int[capacity];
        for (int i = 0; i < size - 1; i++)
        {
            arr1[i] = arr[i];
        }
        delete[] arr;
        arr = arr1;
    }
    size--;
}
int& MyVector::vector_front()
{
    return arr[0];
}
int& MyVector::vector_back()
{
    return arr[size - 1];
}
size_t MyVector::vector_size()
{
    return size;
    
}


void MyVector::print_vector()
{
    for (size_t i = 0; i < vector_size(); ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}