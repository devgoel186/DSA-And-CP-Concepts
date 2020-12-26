#include <iostream>
using namespace std;

int main()
{
    int n1;
    cin >> n1;

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n1 - i; j++)
            cout << "  ";
        for (int j = 0; j < 2*i+1; j++)
        {
            cout << abs((i)-j)+1 << " ";
        }
        cout << "\n";
    }
}
