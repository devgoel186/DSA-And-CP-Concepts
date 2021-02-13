#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    /* While iterating through vectors, we can use multiple techniques, which will be listed here one by one*/
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;

    for (auto it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;

    // reverse iterator pointers rbegin() and rend()
    for (auto it = v.rbegin(); it != v.rend(); it++)
        cout << *it << " ";
    cout << endl;

    /* NORMAL ITERATORS - In normal iterator an ordinary temporary variable is diclare as the iterator,
    * and the iterator gets a copy of the current loop item by value. Any changes made to the temporary
    * copy will not get reflected in the original iterable. */
    for (int itr : v)
    {
        cout << itr << " ";
    }
    cout << endl;

    /* REFERENCE ITERATORS - Reference iterators are declared as a reference variable, 
    * and the iterator gets the value of the current item by reference.
    * So the changes made inside the loop are definitely get affected in the original container itself. */
    for (int &itr : v)
    {
        cout << itr << " ";
    }
    cout << endl;

    /* CONSTANT ITERATORS - Constant iterators are declared as a reference to a constant and in this case,
    * no copy of the current loop item will be made making the execution faster as compared to the above two cases. 
    * This is useful in cases where we don’t want any accidental changes in the iterator value
    * or if we are iterating over large items in a container. If we will try to modify the existing value then the compiler will show errors.*/
    for (const int &itr : v)
    {
        cout << itr << " ";
    }
    cout << endl;
}