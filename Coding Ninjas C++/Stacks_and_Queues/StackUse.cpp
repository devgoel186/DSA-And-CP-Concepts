#include <iostream>
using namespace std;
#include "./StackUsingTemplates.cpp"

int main()
{
    // Creating stack
    // StackUsingArray<int> s;
    StackUsingArray<char> s;
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);

    // top() function
    cout << s.top() << endl;

    // pop() operations
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    // Size using size() function
    cout << "Size = " << s.size() << endl;

    // isEmpty?
    cout << "isEmpty? -> " << s.isEmpty() << endl;
}