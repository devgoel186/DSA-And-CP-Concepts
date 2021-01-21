#include <iostream>
using namespace std;
#include "StackUsingArray.h"
#include <stack> // Any inbuilt heaader files are accessed using <> (angular brackets)

/*Functions in inbuilt stack :
* void push(T)
* void pop()
* T top()
* int size()
* bool empty()
*/

int main()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    cout << s.size() << endl;
    cout << s.empty() << endl;
}
