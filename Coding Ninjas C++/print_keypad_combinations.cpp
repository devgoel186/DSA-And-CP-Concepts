#include <iostream>
#include <string>
using namespace std;

string combos[9] = {"abc", "def", "ghi", "jkl", "mno", "pqr", "stu", "vwx", "yz"};

void keypad_combos(int input, string output)
{
    if (input == 0)
    {
        cout << output << endl;
        return;
    }
    else
    {
        keypad_combos(input / 10, combos[input % 10 - 1][0] + output);
        keypad_combos(input / 10, combos[input % 10 - 1][1] + output);
        if (input % 10 != 9)
            keypad_combos(input / 10, combos[input % 10 - 1][2] + output);
    }
}

int main()
{
    int input;
    cin >> input;
    string output;
    keypad_combos(input, output);
}