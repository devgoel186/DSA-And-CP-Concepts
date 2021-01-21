template <typename T>
class QueueUsingDynamicArray
{
    T *data;
    int backIndex;
    int frontIndex;
    int size;
    int capacity;

public:
    QueueUsingDynamicArray()
    {
        data = new T[5];
        backIndex = 0;
        frontIndex = -1;
        size = 0;
        capacity = 5;
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
            T *newData = new T[capacity * 2];
            int j = 0;
            for (int i = frontIndex; i < capacity; i++)
            {
                newData[j] = data[i];
                j++;
            }
            for (int i = 0; i < frontIndex; i++)
            {
                newData[j] = data[i];
                j++;
            }

            delete[] data;
            data = newData;
            frontIndex = 0;
            backIndex = capacity;
            capacity *= 2;
            // cout << "Queue is full!" << endl;
            // return;
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
