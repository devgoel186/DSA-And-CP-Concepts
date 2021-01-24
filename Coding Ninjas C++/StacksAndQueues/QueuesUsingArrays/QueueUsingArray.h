template <typename T>
class QueueUsingArray
{
    T *data;
    int backIndex;
    int frontIndex;
    int size;
    int capacity;

public:
    QueueUsingArray(int s)
    {
        data = new T[s];
        backIndex = 0;
        frontIndex = -1;
        size = 0;
        capacity = s;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(T element)
    {
        if (size == capacity)
        {
            cout << "Queue is full!" << endl;
            return;
        }
        data[backIndex] = element;
        backIndex = (backIndex + 1) % capacity;
        if (frontIndex == -1)
            frontIndex = 0;
        size++;
    }

    T front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        return data[frontIndex];
    }

    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        T ans = data[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        size--;
        if (isEmpty())
        {
            frontIndex = -1;
            backIndex = 0;
        }
        return ans;
    }
};
