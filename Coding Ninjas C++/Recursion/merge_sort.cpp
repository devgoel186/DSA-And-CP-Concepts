#include <iostream>
using namespace std;

void merge(int a[], int mid, int si, int ei)
{
    int *arr = new int[ei - si + 1];
    int i = si, j = mid + 1;
    int count = 0;
    while (i <= mid && j <= ei)
    {
        if (a[i] <= a[j])
        {
            arr[count] = a[i];
            i++;
        }
        else
        {
            arr[count] = a[j];
            j++;
        }
        count++;
    }
    for (; j <= ei; j++)
    {
        arr[count] = a[j];
        count++;
    }
    for (; i <= mid; i++)
    {
        arr[count] = a[i];
        count++;
    }

    for (int k = 0; k < count; k++)
        a[si + k] = arr[k];
}

void merge_sort(int a[], int si, int ei)
{
    if (si >= ei)
        return;
    else
    {
        int mid = (si + ei) / 2;
        merge_sort(a, si, mid);
        merge_sort(a, mid + 1, ei);
        merge(a, mid, si, ei);
    }
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    merge_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}