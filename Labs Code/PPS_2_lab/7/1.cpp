#include <iostream>

using namespace std;

class Complex
{
    int real;
    int img;

public:
    Complex(int real = 0, int img = 0)
    {
        this->real = real;
        this->img = img;
    }

    void operator++(int)
    {
        this->real++;
        this->img++;
    }

    void print()
    {
        cout << this->real << " " << this->img;
    }
};

int main()
{
    int real, img;
    cin >> real >> img;

    Complex c(real, img);
    c++;
    c.print();

    return 0;
}