#include <iostream>
using namespace std;
#include "./StackUsingArray.h"

int main()
{
    StackUsingArray<int> s(5);
    s.push(99);
    s.push(101);
    s.push(103);
    s.push(105);
    s.push(107);

    cout << "Size = " << s.getSize() << endl;
    cout << "POP -> " << s.pop() << endl;
    cout << "Size = " << s.getSize() << endl;
    cout << "TOP -> " << s.top() << endl;
    cout << "Size = " << s.getSize() << endl;
    cout << "isEmpty? " << s.isEmpty() << endl;
}