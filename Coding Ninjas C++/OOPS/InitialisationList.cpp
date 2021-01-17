#include <iostream>
using namespace std;

class ILists
{
public:
    int age;
    const int rollNo;

    ILists(int age, int r) : /* age(age),*/ rollNo(r) // Since 'age' is not a const variable, we can initialise
                                                      // it in initialisation lists or we can initialise it in the constructor
                                                      // However, const members can be initialised in the initiialisation lists only
    {
        this->age = age;
    }
};