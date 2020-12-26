#include <iostream>
using namespace std;

int main()
{
    int n1;
    cin >> n1;

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            if((i+j)%2 == 0)
                cout << "1" << " ";
            else
                cout << "0" << " ";
        }
        cout << "\n";
    }
}
