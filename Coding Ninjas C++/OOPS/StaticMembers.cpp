#include <iostream>
using namespace std;
#include "Student.cpp"

int main()
{
    Student s1;
    cout << s1.rollNumber << " " << s1.age << endl;
    cout << s1.totalStudents << endl;

    s1.totalStudents = 20;

    Student s2;

    cout << "s1 - " << s1.totalStudents << endl;
    cout << "s2 - " << s2.totalStudents << endl;
    cout << "Total Students - " << Student ::totalStudents << endl;
}
