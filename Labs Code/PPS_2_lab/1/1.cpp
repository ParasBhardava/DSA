#include <iostream>
#include <math.h>

using namespace std;

bool is_prime(int num)
{
    int i, sqrt_of_num = sqrt(num);

    if (num == 1)
        return false;

    else if (num == 2)
        return true;

    else if (num % 2)
    {
        for (i = 3; i <= sqrt_of_num; i += 2)
            if (num % i == 0)
                break;
    }
    if (i > sqrt_of_num)
        return true;
        
    return false;
}

int main()
{

    int n, num;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (is_prime(num) == true)
            cout << num << " ";
    }

    return 0;
}