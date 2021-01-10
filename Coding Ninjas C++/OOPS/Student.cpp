#include <iostream>
using namespace std;

class Student
{
public:
    int rollNumber;
    int age;
    static int totalStudents;
};

int Student ::totalStudents = 0;