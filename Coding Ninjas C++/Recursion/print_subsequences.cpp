#include <iostream>
#include <string>
using namespace std;

void print_subsequences(string input, string output)
{
    if (input == "")
    {
        cout << output << endl;
        return;
    }
    else
    {
        print_subsequences(input.substr(1), output);
        print_subsequences(input.substr(1), output + input[0]);
    }
}

int main()
{
    string input;
    cin >> input;
    string output;
    print_subsequences(input, output);
}
