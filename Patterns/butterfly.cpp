#include <iostream>
using namespace std;

int main()
{
    int n1;
    cin >> n1;

    for (int i = 0; i < 2*n1-1; i++)
    {
        for (int j = 0; j < 2*n1-1; j++)
        {
            if(i<n1 && (j<=i || j>=2*n1-i-2))
                cout << "* ";
            else if (i >= n1 && (j >= i || j <= 2 * n1 - i - 2))
                cout << "* ";
            else
                cout << "  ";   
        }
        cout << "\n";
    }
}
