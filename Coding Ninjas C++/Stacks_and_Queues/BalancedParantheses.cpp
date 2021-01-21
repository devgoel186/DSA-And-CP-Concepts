#include <iostream>
using namespace std;
#include <stack>
#include <string>

string takeInput()
{
    cout << "Enter the expression - " << endl;
    string a;
    cin >> a;
    return a;
}

int main()
{
    string str = takeInput();
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '{' || str[i] == '(' || str[i] == '[')
            s.push(str[i]);
        else
        {
            switch (str[i])
            {
            case '}':
                if (!s.empty() && s.top() == '{')
                    s.pop();
                else
                {
                    cout << "Not balanced!";
                    return 0;
                }
                break;
            case ')':
                if (!s.empty() && s.top() == '(')
                    s.pop();
                else
                {
                    cout << "Not balanced!";
                    return 0;
                }
                break;
            case ']':
                if (!s.empty() && s.top() == '[')
                    s.pop();
                else
                {
                    cout << "Not balanced!";
                    return 0;
                }
                break;
            default:
                break;
            }
        }
    }

    s.empty() ? cout << "Balanced!" : cout << "Not balanced!" << endl;
}
