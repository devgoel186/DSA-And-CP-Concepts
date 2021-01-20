#include <iostream>
using namespace std;
#include "./StackUsingArray.cpp"

int main()
{
    // Creating stack
    StackUsingArray s(4);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    // top() function
    cout << s.top() << endl;

    // pop() operations
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    // Size using size() function
    cout << "Size = " << s.size() << endl;

    // isEmpty?
    cout << "isEmpty? -> " << s.isEmpty() << endl;
}