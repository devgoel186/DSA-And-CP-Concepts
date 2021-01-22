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
            return 0;
        return head->data;
    }

    void enqueue(T element)
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

    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!";
            return 0;
        }
        T ans = head->data;
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }
};
