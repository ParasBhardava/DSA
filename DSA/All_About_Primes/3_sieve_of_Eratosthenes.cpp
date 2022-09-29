#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;
bool sieve[N + 1];

void createSieve()
{
    sieve[0] = false;
    sieve[1] = false;
    for (int i = 2; i <= N; i++)
        sieve[i] = true;

    for (int i = 2; i * i <= N; i++)
    {
        if (sieve[i] == true)
        {
            for (int j = i * i; j <= N; j += i)
                sieve[j] = false;
        }
    }
}

// Time complexity : O(n * log(logn))

int main()
{
    createSieve();

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        if (sieve[n])
            cout << "Prime\n";

        else
            cout << "Not Prime\n";
    }

    for (int i = 0; i <= N; i++)
        cout << sieve[i] << " ";

    return 0;
}