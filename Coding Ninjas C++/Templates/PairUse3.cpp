#include <iostream>
using namespace std;
#include "./Pair2.cpp"

int main()
{
    Pair<int, int> p2;
    p2.setX(2);
    p2.setY(4);

    Pair<Pair<int, int>, int> p1;
    p1.setX(p2);
    p1.setY(100);

    cout << p1.getX().getX() << " " << p1.getX().getY() << " " << p1.getY() << endl;
    // Will drop decimal part for x as x is integer
}
