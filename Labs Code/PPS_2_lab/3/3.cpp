#include <iostream>
#include <cstring>
#define PI 3.14

float area(float radius)
{
    return PI * radius * radius;
}

float area(double length, double width)
{
    return length * width;
}

float area(double length)
{
    return length * length;
}

int main()
{
    char shape[10];
    float radius;
    double length, width;

    std::cin >> shape;
    if (!strcmp(shape, "circle"))
    {
        std::cin >> radius;
        std::cout << area(radius);
    }

    else if (!strcmp(shape, "rectangle"))
    {
        std::cin >> length >> width;
        std::cout << area(length, width);
    }

    else
    {
        std::cin >> length;
        std::cout << area(length);
    }

    return 0;
}