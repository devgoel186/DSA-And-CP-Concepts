#include <iostream>
using namespace std;
#include "./InitialisationList.cpp"

int main()
{
    ILists s1(20, 40);
    // s1.age = 20;
    // s1.rollNo = 40;
    cout << s1.age << " " << s1.rollNo << endl;
}