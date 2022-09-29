#include <iostream>

using namespace std;

int main()
{

    int num, reverse_num = 0;
    cin >> num;

    while (num)
    {
        int rem = num % 10;
        num /= 10;
        reverse_num = reverse_num * 10 + rem;
    }

    cout << reverse_num;

    return 0;
}
