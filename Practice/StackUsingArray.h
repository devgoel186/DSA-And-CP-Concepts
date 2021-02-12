#include <iostream>
using namespace std;

template <typename T>
class StackUsingArray
{
    T *arr;
    int nextIndex;
    int capacity;

public:
    StackUsingArray(int size)
    {
        arr = new T[size];
        nextIndex = 0;
        capacity = size;
    }

    int getSize()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        return nextIndex == 0;
    }

    void push(T element)
    {
        if (nextIndex == capacity)
            cout << "Stack is Full!" << endl;
        arr[nextIndex] = element;
        nextIndex++;
    }

    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty!" << endl;
            return 0;
        }
        nextIndex--;
        return arr[nextIndex];
    }

    T top()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty!" << endl;
            return 0;
        }
        return arr[nextIndex - 1];
    }
};