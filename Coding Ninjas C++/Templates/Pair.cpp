#include <iostream>
using namespace std;

template <typename T>

class Pair
{
    // int x;
    // int y;
    T x;
    T y;

public:
    void setX(T x)
    {
        this->x = x;
    }

    T getX()
    {
        return x;
    }

    void setY(T y)
    {
        this->y = y;
    }

    T getY()
    {
        return y;
    }
};