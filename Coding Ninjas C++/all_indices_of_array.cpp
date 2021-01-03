#include <iostream>
using namespace std;

int all_indices(int a[], int size, int x, int output = 0)
{
    if (size == 0)
        return 0;
    else
    {
        output = all_indices(a + 1, size - 1, x, output);
        if (a[0] == x)
            return output + 1;
        else
            return output;
    }
}

int main()
{
    int n;
    cout << "Enter size of array : ";
    cin >> n;

    int *a = new int[n];
    cout << "Enter array elements : ";
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    int x;
    cout << "Enter number to be searched : ";
    cin >> x;

    cout << all_indices(a, n, x);
}