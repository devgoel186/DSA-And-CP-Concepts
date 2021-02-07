#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue
{
    vector<int> q;

public:
    PriorityQueue()
    {
    }

    bool isEmpty()
    {
        return q.size() == 0;
    }

private:
    void rearrangeWhenInserting(int childIndex)
    {
        if (childIndex == 0)
            return;
        int parentIndex = (childIndex - 1) / 2;
        if (q[childIndex] < q[parentIndex])
        {
            swap(q[childIndex], q[parentIndex]);
            rearrangeWhenInserting(parentIndex);
        }
        return;
    }

    void rearrangeWhenRemoving(int presentIndex)
    {
        int childIndex1 = 2 * presentIndex + 1;
        int childIndex2 = 2 * presentIndex + 2;
        // Base case
        if (childIndex1 < q.size() && childIndex2 < q.size())
            return;

        // Recursion
        if (q[presentIndex] > q[childIndex1])
        {
            swap(q[presentIndex], q[childIndex1]);
            presentIndex = childIndex1;
        }
        else if (q[presentIndex] > q[childIndex2])
        {
            swap(q[presentIndex], q[childIndex2]);
            presentIndex = childIndex2;
        }
        else
            return;
        rearrangeWhenRemoving(presentIndex);
    }

public:
    // We are inserting in a MinHeap structure for our priority queue here
    void
    insert(int element)
    {
        q.push_back(element);
        rearrangeWhenInserting(q.size() - 1);
    }

    int getMin()
    {
        if (isEmpty())
            return 0;
        return q[0];
    }

    int getSize()
    {
        return q.size();
    }

    // Considering MinHeap as the data structure
    int removeMin()
    {
        if (isEmpty())
            return 0;
        int min = q[0];
        swap(q[0], q[q.size() - 1]);
        q.pop_back();

        // Rearrange function defined above
        rearrangeWhenRemoving(0);

        return min;
    }
};
