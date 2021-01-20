#include <iostream>
#include <climits>
using namespace std;

class StackUsingArray
{
private:
    int *data;
    int nextIndex;
    int capacity;

public:
    StackUsingArray(int size)
    {
        data = new int[size];
        nextIndex = 0;
        capacity = size;
    }

    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        return nextIndex == 0;
    }

    void push(int element)
    {
        if (nextIndex == capacity)
        {
            cout << "Stack full. Could not insert value -> " << element << endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
};