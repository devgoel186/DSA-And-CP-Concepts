#include <iostream>
using namespace std;

class ComplexNumbers
{
private:
    int real, imaginary;

public:
    ComplexNumbers(int real, int imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }

    void plus(ComplexNumbers obj)
    {
        this->real += obj.real;
        this->imaginary += obj.imaginary;
    }

    void multiply(ComplexNumbers obj)
    {
        int real = (this->real * obj.real) - (this->imaginary * obj.imaginary);
        this->imaginary = (this->real * obj.imaginary) + (this->imaginary * obj.real);
        this->real = real;
    }

    void print()
    {
        cout << this->real << " + " << this->imaginary << "i" << endl;
    }
};