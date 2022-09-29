#include <iostream>

using namespace std;

class point
{
public:
    int x, y;

    point() {}

    point(int a, int b)
    {
        x = a;
        y = b;
    }
};

class rectangle
{
public:
    int i;
    point p[4];

    rectangle()
    {
        i = 0;
    }

    void set(int a, int b)
    {
        p[i] = point(a, b);
        i++;
    }

    void move_left(int val)
    {
        for (int i = 0; i < 4; i++)
            p[i].x -= val;
    }

    void move_right(int val)
    {
        for (int i = 0; i < 4; i++)
            p[i].x += val;
    }

    void move_up(int val)
    {
        for (int i = 0; i < 4; i++)
            p[i].y += val;
    }

    void move_down(int val)
    {
        for (int i = 0; i < 4; i++)
            p[i].y -= val;
    }

    void alter(char ch1, char ch2, int val)
    {
        if (ch1 == 'I')
        {
            if (ch2 == 'L')
            {
                p[0].x -= val;
                p[2].x -= val;
            }

            else if (ch2 == 'R')
            {
                p[1].x += val;
                p[3].x += val;
            }

            else if (ch2 == 'T')
            {
                p[0].y += val;
                p[1].y += val;
            }

            else
            {
                p[2].y -= val;
                p[3].y -= val;
            }
        }

        else
        {
            if (ch2 == 'L')
            {
                p[0].x += val;
                p[2].x += val;
            }
            else if (ch2 == 'R')
            {
                p[1].x -= val;
                p[3].x -= val;
            }
            else if (ch2 == 'T')
            {
                p[0].y -= val;
                p[1].y -= val;
            }

            else
            {
                p[2].y += val;
                p[3].y += val;
            }
        }
    }

    void print()
    {
        for (int i = 0; i < 4; i++)
            cout << p[i].x << " " << p[i].y << "\n";
    }
};

int main()
{

    rectangle r;
    for (int i = 0; i < 4; i++)
    {
        int a, b;
        cin >> a >> b;
        r.set(a, b);
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char ch;
        int val;
        cin >> ch;

        if (ch == 'L')
        {
            cin >> val;
            r.move_left(val);
        }

        else if (ch == 'R')
        {
            cin >> val;
            r.move_right(val);
        }

        else if (ch == 'U')
        {
            cin >> val;
            r.move_up(val);
        }

        else if (ch == 'D')
        {
            cin >> val;
            r.move_down(val);
        }

        else
        {
            char ch1, ch2;
            cin >> ch1 >> ch2 >> val;
            r.alter(ch1, ch2, val);
        }
    }

    r.print();

    return 0;
}