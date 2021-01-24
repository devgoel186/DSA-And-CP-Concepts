#include <iostream>
using namespace std;
#include "./StackUsingLL.cpp"

int main()
{
    // Creating stack
    // StackUsingArray<int> s;
    Stack<int> s;
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);

    // // top() function
    cout << s.top() << endl;

    // // pop() operations
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    // Size using size() function
    cout << "Size = " << s.getSize() << endl;

    // isEmpty?
    cout << "isEmpty? -> " << s.isEmpty() << endl;
}