#include <iostream>
using namespace std;

void remove_duplicates(char a[])
{
    if (a[0] == '\0' || a[1] == '\0')
        return;
    else
    {
        remove_duplicates(a + 1);
        if (a[0] == a[1])
        {
            int i = 0;
            for (; a[i] != '\0'; i++)
                a[i] = a[i + 1];
        }
    }
}

int main()
{
    // int n;
    // cin >> n;
    // char *p = new char[n];
    // for (int i = 0; i < n; i++)
    //     cin >> p[i];
    char str[100];
    cin >> str;
    remove_duplicates(str);
    cout << str << endl;
}