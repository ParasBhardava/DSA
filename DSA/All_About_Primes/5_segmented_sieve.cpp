/*

1 <= L, R <= 10^12;
R - L <= 10^6;

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;
bool sieve[N + 1];

void createSieve()
{
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

vector<int> generatePrimes(int n)
{
    vector<int> ds;

    for (int i = 2; i <= n; i++)
    {
        if (sieve[i] == true)
            ds.push_back(i);
    }

    return ds;
}

int main()
{
    createSieve();
    int t;
    cin >> t;

    while (t--)
    {
        int l, r;
        cin >> l >> r;

        // Step 1 : Generate all primes till sqrt(r)
        vector<int> primes = generatePrimes(sqrt(r));

        // Step 2 : Create a dummy of size r - l + 1 and make everyone as 1
        bool dummy[r - l + 1];
        for (int i = 0; i < r - l + 1; i++)
            dummy[i] = true;

        // Step 3 : For all prime number marks its multiple as false
        for (auto pr : primes)
        {
            int firstMultiple = (l / pr) * pr;

            if (firstMultiple < l)
                firstMultiple += pr;

            for (int j = max(firstMultiple, pr * pr); j <= r; j += pr)
                dummy[j - l] = false;
        }

        // Step 4 : Get all the primes
        for (int i = l; i <= r; i++)
        {
            if (dummy[i - l] == true)
                cout << i << " ";
        }

        cout << "\n";
    }

    return 0;
}