#include<iostream>
using namespace std;

int main() {
    int n1, n2;
    cin >> n1 >> n2;

    for (int i=0; i<n1; i++) {
        for(int j=0; j<n2; j++) {
            if(i==0 || i==n1-1)
                cout << "* ";
            else if(j==0 || j==n2-1)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << "\n";
    }
}

