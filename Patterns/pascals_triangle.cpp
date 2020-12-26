// A Pascal's Triangle is one which is a half pyramid pattern 
// with coefficients equal to binomial coefficients, i.e, nC0, nC1, etc.

#include <iostream>
using namespace std;

int factorial(int n) {
    int fact = 1;
    for(int i=2; i<=n; i++) {
        fact*=i;
    }
    return fact;
}

int main()
{
    int n1;
    cin >> n1;

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n1 - i; j++)
            cout << " ";
        for (int j = 0; j < i + 1; j++)
        {
            cout << factorial(i)/(factorial(j)*factorial(i-j)) << " ";
        }
        cout << "\n";
    }
}
