#include <iostream>
#include <iomanip>
using namespace std;

class ComplexNumber
{
    float real;
    float img;

public:
    ComplexNumber(float real = 0, float img = 0)
    {
        this->real = real;
        this->img = img;
    }

    ComplexNumber operator+(ComplexNumber const &complex2)
    {
        ComplexNumber result;
        result.real = this->real + complex2.real;
        result.img = this->img + complex2.img;
        return result;
    }

    ComplexNumber operator*(ComplexNumber const &complex2)
    {
        ComplexNumber result;
        result.real = (this->real * complex2.real) - (this->img * complex2.img);
        result.img = (this->real * complex2.img) + (this->img * complex2.real);
        return result;
    }

    ComplexNumber operator*(float val)
    {
        ComplexNumber result;
        result.real = this->real * val;
        result.img = this->img * val;
        return result;
    }

    void print()
    {
        cout << fixed << setprecision(2);
        cout << real << " " << img;
    }
};

int main()
{

    float real, imaginary;
    cin >> real >> imaginary;
    ComplexNumber result(real, imaginary);

    int n, i;
    cin >> n;

    int operation_code;
    float operand2_float;
    for (i = 0; i < n; i++)
    {
        cin >> operation_code;
        if (1 == operation_code)
        {
            // addition of two ComplexNumber objects
            cin >> real >> imaginary;
            ComplexNumber operand2_complex_number(real, imaginary);
            result = result + operand2_complex_number;
        }

        else if (2 == operation_code)
        {
            // multiplication of two ComplexNumber objects
            cin >> real >> imaginary;
            ComplexNumber operand2_complex_number(real, imaginary);
            result = result * operand2_complex_number;
        }

        else if (3 == operation_code)
        {
            // multiplication of ComplexNumber object and a float
            cin >> operand2_float;
            result = result * operand2_float;
        }

        else
        {
            cout << "Invalid operation" << endl;
        }
        result.print();
        cout << endl;
    }

    return 0;
}