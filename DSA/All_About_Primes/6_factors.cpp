#include <bits/stdc++.h>
using namespace std;

int primeFactors(int num)
{
    int count = 0;
    for (int i = 2; i * i <= num; i++)
    {
        while (num % i == 0)
        {
            cout << i << " ";
            num = num / i;
        }
    }

    if (num >= 2)
        cout << num << " ";

    return count;
}

int factors(int num)
{
    int count = 0;
    for (int i = 1; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            cout << i << " ";
            if (num / i != i)
            {
                cout << num / i << " ";
                count++;
            }
        }
    }

    return count;
    // Time complexity : O(sqrt(n))
    // if we use (i <= sqrt(n)) then time complexity is O(sqrt(n) * logn)
}

int main()
{
    int n;
    cin >> n;

    factors(n);
    cout << "\n";
    primeFactors(n);

    return 0;
}

/*

36

1   36        ---> (i   n/i)
2   18
3   12
4   9
6   6
----------
9    4
12   3
18   2
366  1


*/