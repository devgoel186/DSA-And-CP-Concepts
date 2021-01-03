#include <iostream>
using namespace std;

int first_index(int a[], int size, int x)
{
    if (size == 0)
        return -1;

    if (a[0] == x)
        return 0;
    else
    {
        int temp = first_index(a + 1, size - 1, x);
        return (temp != 1) ? temp + 1 : -1;
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

    cout << first_index(a, n, x);
}