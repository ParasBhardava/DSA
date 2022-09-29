#include <iostream>
#include <string>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;
using std::string;

#define PI 3.14

class Shape
{
public:
    virtual double area() = 0;
    virtual double perimeter() = 0;
};

class Square : public Shape
{
    double length;

public:
    Square(double length)
    {
        this->length = length;
    }

    double area()
    {
        return length * length;
    }

    double perimeter()
    {
        return 4 * length;
    }
};

class Rectangle : public Shape
{
    double length, width;

public:
    Rectangle(double length, double width)
    {
        this->length = length;
        this->width = width;
    }

    double area()
    {
        return length * width;
    }

    double perimeter()
    {
        return 2 * (length + width);
    }
};

class Circle : public Shape
{
    double radius;

public:
    Circle(double radius)
    {
        this->radius = radius;
    }

    double area()
    {
        return PI * radius * radius;
    }

    double perimeter()
    {
        return 2 * PI * radius;
    }
};

int main()
{

    int n;
    cin >> n;

    Shape **sp = new Shape *[n];

    char shape_type;
    double num1, num2;
    for (int i = 0; i < n; i++)
    {
        getchar();
        cin >> shape_type;
        switch (shape_type)
        {
        case 'S':
            cin >> num1;
            sp[i] = new Square(num1);
            break;
        case 'R':
            cin >> num1 >> num2;
            sp[i] = new Rectangle(num1, num2);
            break;
        case 'C':
            cin >> num1;
            sp[i] = new Circle(num1);
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << fixed << setprecision(2);
        cout << sp[i]->area() << " ";
        cout << sp[i]->perimeter() << endl;
    }

    return 0;
}