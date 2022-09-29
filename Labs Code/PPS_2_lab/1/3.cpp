#include <iostream>

using namespace std;

int main()
{

    int year, count = 0;
    cin >> year;

    while (count < 15)
    {
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        {
            cout << year << " ";
            count = count + 1;
        }
        year += 1;
    }

    return 0;
}