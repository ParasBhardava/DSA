#include <iostream>
#include <cstdio>

using namespace std;

class Rectangle
{
    double x_coord;
    double y_coord;
    double length;
    double width;

public:
    Rectangle(double x, double y, double length, double width)
    {
        this->x_coord = x;
        this->y_coord = y;
        this->length = length;
        this->width = width;
    }

    void print()
    {
        printf("%.2f %.2f %.2f %.2f", x_coord, y_coord, length, width);
    }

    Rectangle operator<<(double val)
    {
        Rectangle temp(x_coord, y_coord, length, width);
        temp.x_coord -= val;
        return temp;
    }

    Rectangle operator>>(double val)
    {
        Rectangle temp(x_coord, y_coord, length, width);
        temp.x_coord += val;
        return temp;
    }

    Rectangle operator+(double val)
    {
        Rectangle temp(x_coord, y_coord, length, width);
        temp.length += val;
        return temp;
    }

    Rectangle operator-(double val)
    {
        Rectangle temp(x_coord, y_coord, length, width);
        temp.length -= val;
        return temp;
    }
};

int main()
{
    double x, y, length, width;
    cin >> x >> y >> length >> width;
    Rectangle R(x, y, length, width);

    int n;
    char ch;
    double val;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ch >> val;

        switch (ch)
        {
        case 'L':
            R = R << val;
            break;

        case 'R':
            R = R >> val;
            break;

        case 'I':
            R = R + val;
            break;

        case 'D':
            R = R - val;
            break;
        }
    }

    R.print();

    return 0;
}