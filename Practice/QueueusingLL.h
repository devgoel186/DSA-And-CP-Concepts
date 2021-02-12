#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class QueueUsingLL
{
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    QueueUsingLL()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    T front()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return 0;
        }
        return head->data;
    }

    void push(T element)
    {
        Node<T> *newNode = new Node<T>(element);
        size++;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = tail->next;
    }

    T pop()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return 0;
        }
        size--;
        T ans = head->data;
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        return ans;
    }
};