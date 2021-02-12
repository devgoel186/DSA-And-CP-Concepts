#include <iostream>
using namespace std;
#include "./QueueUsingLL.h"

int main()
{
    QueueUsingLL<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout << "Size = " << q.getSize() << endl;
    cout << "POP -> " << q.pop() << endl;
    cout << "Size = " << q.getSize() << endl;
    cout << "FRONT -> " << q.front() << endl;
    cout << "Size = " << q.getSize() << endl;
    cout << "isEmpty? " << q.isEmpty() << endl;

    return 0;
}