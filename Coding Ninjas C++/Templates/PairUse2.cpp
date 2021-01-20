#include <iostream>
using namespace std;
#include "./Pair2.cpp"

int main()
{
    Pair<int, double> p1;
    p1.setX(101.12211212);
    p1.setY(100.123);

    cout << p1.getX() << " " << p1.getY() << endl;
    // Will drop decimal part for x as x is integer
}
