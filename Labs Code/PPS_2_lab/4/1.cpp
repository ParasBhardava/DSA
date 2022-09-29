#include <iostream>
using namespace std;

class MovingPoint
{
    int x_coord, y_coord;

public:
    MovingPoint()
    {
        x_coord = 0;
        y_coord = 0;
    }

    void initialize(int x, int y)
    {
        static int count = 1;
        if (count == 1)
        {
            x_coord = x;
            y_coord = y;
        }
        count++;
    }

    void move_left(int x)
    {
        x_coord -= x;
    }

    void move_right(int x)
    {
        x_coord += x;
    }

    void move_up(int y)
    {
        y_coord += y;
    }

    void move_down(int y)
    {
        y_coord -= y;
    }

    void print_current_position()
    {
        cout << x_coord << " " << y_coord;
    }
};

int main()
{

    MovingPoint mp;
    int x, y, n, i, units;
    char direction;

    std::cin >> x >> y;
    mp.initialize(x, y);

    std::cin >> n;
    for (i = 0; i < n; i++)
    {
        std::cin >> direction >> units;
        switch (direction)
        {
        case 'L':
            mp.move_left(units);
            break;
        case 'R':
            mp.move_right(units);
            break;
        case 'U':
            mp.move_up(units);
            break;
        case 'D':
            mp.move_down(units);
            break;
        }
    }

    // This call to initialize method should be ingored
    // If this method is called twice, it should be ignored as per specification
    // This call should not change the state of the object
    mp.initialize(0, 0);

    // Printing final position of the point as output
    mp.print_current_position();

    return 0;
}