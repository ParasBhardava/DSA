#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;
int smallestprimeFactor[N + 1];

void createSieve()
{
    for (int i = 0; i <= N; i++)
        smallestprimeFactor[i] = i;

    for (int i = 2; i * i <= N; i++)
    {
        if (smallestprimeFactor[i] == i)
        {
            for (int j = i * i; j <= N; j += i)
            {
                if (smallestprimeFactor[j] == j)
                    smallestprimeFactor[j] = i;
            }
        }
    }
}

// Time Complexity :

int main()
{
    // nlog(logn)
    createSieve();

    int t;
    cin >> t;

    // nlogn : any numbers has atmost logn prime factors
    while (t--)
    {
        int n;
        cin >> n;

        while (n != 1)
        {
            cout << smallestprimeFactor[n] << " ";
            n = n / smallestprimeFactor[n];
        }

        cout << "\n";
    }

    return 0;
}