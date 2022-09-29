#include <iostream>

using namespace std;

int main()
{

    int num, binary[50], i = 0, rem;
    cin >> num;

    while (num)
    {
        rem = num % 2;
        num /= 2;
        binary[i] = rem;
        i++;
    }

    for (int j = i - 1; j >= 0; j--)
        cout << binary[j];

    return 0;
}