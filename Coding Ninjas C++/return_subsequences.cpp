#include <iostream>
#include <string>
using namespace std;

int return_subsequences(string input, string output[])
{
    if (input.length() == 0)
    {
        output[0] = "";
        return 1;
    }
    else
    {
        int size = return_subsequences(input.substr(1), output);
        for (int i = 0; i < size; i++)
        {
            output[size + i] = input[0] + output[i];
        }
        return 2 * size;
    }
}

int main()
{
    string input;
    cin >> input;
    string *p = new string[1000];
    int subSize = return_subsequences(input, p);
    cout << "No. of subsequences = " << subSize << endl;
    cout << "Subsequences - [\"\", ";
    int i = 1;
    for (; i < subSize - 1; i++)
        cout << p[i] << ", ";
    cout << p[i] << "]" << endl;
}