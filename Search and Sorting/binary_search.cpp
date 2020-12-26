#include<iostream>
using namespace std;

int main() {
    const int n = 8;
    // cin >> n;

    int arr[n];
    cout << "Enter elements for array of size 8";
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    int x;
    cin >> x;

    int l = 0, u = n-1;

    while(l <= u) {
        int m = (l + u) / 2;
        if(x == arr[m]) {
            cout << "Found at index - " << m;
            break;
        }
        else if(x > arr[m]) 
            l = m+1;
        else
            u = m-1;
    }

    if(l > u)
        cout << "Not found!";
}