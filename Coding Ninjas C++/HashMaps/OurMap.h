#include <iostream>
using namespace std;

template <typename T>
class MapNode
{
public:
    string key;
    T value;
    MapNode *next;

    MapNode(string key, T value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~MapNode()
    {
        delete next;
    }
};

template <typename T>
class OurMap
{
    MapNode<T> **buckets; // The nodes in our hash map are pointers to a pointer 2,
                          // where the pointer 2 points to the linked list.
    int count;
    int bucketSize;

public:
    OurMap()
    {
        count = 0;
        bucketSize = 5;
        buckets = new MapNode<T> *[bucketSize]; // Initialize a bucket of type MapNode *
        for (int i = 0; i < bucketSize; i++)
        {
            buckets[i] = NULL;
        }
    }

    ~OurMap()
    {
        for (int i = 0; i < bucketSize; i++)
        {
            delete buckets[i];
        }
        delete[] buckets;
    }

private:
    int getBucketIndex(string key)
    {
        int hashCode = 0;
        int currentCoeff = 1;
        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashCode += key[i] * currentCoeff;
            hashCode = hashCode % bucketSize;
            currentCoeff *= 37;
            currentCoeff = currentCoeff % bucketSize;
        }
        return hashCode % bucketSize;
    }

public:
    int size()
    {
        return count;
    }

    T getValue(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<T> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
                return head->value;
            head = head->next;
        }
        return 0;
    }

    void rehash()
    {
        MapNode<T> **temp = buckets;
        buckets = new MapNode<T> *[2 * bucketSize];
        for (int i = 0; i < 2 * bucketSize; i++)
            buckets[i] = NULL;
        int oldBucketCount = bucketSize;
        bucketSize *= 2;
        count = 0;
        for (int i = 0; i < oldBucketCount; i++)
        {
            MapNode<T> *head = temp[i];
            while (head != NULL)
            {
                string key = head->key;
                T value = head->value;
                insert(key, value);
                head = head->next;
            }
        }
        for (int i = 0; i < oldBucketCount; i++)
        {
            MapNode<T> *head = temp[i];
            delete head;
        }
        delete[] temp;
    }

    double getLoadFactor()
    {
        return (1.0 * count) / bucketSize;
    }

    void insert(string key, T value)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<T> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        MapNode<T> *node = new MapNode<T>(key, value);
        node->next = head;
        buckets[bucketIndex] = node;
        count++;
        double loadFactor = (1.0 * count) / bucketSize;
        if (loadFactor > 0.7)
            rehash();
    }

    T remove(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<T> *head = buckets[bucketIndex];
        MapNode<T> *prev = head;
        while (head != NULL)
        {
            if (head->key == key)
            {
                T value = head->value;
                prev->next = head->next;
                head->next = NULL;
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }
};
