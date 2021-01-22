#include <iostream>
using namespace std;
#include <queue>

int main()
{
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    cout << q.front() << " " << q.back() << endl;
    q.pop();
    cout << q.front() << " " << q.back() << endl;

    cout << q.size() << endl;
    cout << q.empty() << endl;

    while (!q.empty())
    {
        cout << q.front() << " " << q.back() << endl;
        cout << "Size = " << q.size() << "\n\n";
        q.pop();
    }
}