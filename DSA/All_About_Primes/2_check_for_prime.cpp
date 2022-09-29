#include <bits/stdc++.h>
using namespace std;

bool isPrime(int num)
{
    int count = 0;
    for (int i = 1; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            count++;
            if (num / i != i)
                count++;
        }
    }

    return count == 2;
}
// Time complexity : O(sqrt(n))
// if we use (i <= sqrt(n)) then time complexity is O(sqrt(n) * logn)

int main()
{
    int n;
    cin >> n;

    cout << isPrime(n) << "\n";

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
36   1


*/