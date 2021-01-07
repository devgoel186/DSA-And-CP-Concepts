#include <iostream>
using namespace std;

int last_index(int a[], int size, int x)
{
    if (size == 0)
        return -1;
    int temp = last_index(a + 1, size - 1, x);

    return (temp == -1) ? (a[0] == x) ? 0 : -1 : temp + 1;
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

    cout << last_index(a, n, x);
}