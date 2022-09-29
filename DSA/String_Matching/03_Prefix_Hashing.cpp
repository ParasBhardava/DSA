#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long power(long long base, long long n, long long MOD)
{
    long long ans = 1;
    while (n)
    {
        if (n & 1)
        {
            ans = ((ans * base) % MOD);
            n = n - 1;
        }

        else
        {
            n = n >> 1;
            base = ((base * base) % MOD);
        }
    }

    return ans;
}

class prefixHashing
{

    vector<long long> prefixHash;

public:
    prefixHashing(string &s)
    {
        int n = s.size();
        long long p = 1;
        long long hash = 0;

        for (int i = 0; i < n; i++)
        {
            hash = (hash + (((s[i] - 'a' + 1) * p) % MOD)) % MOD;
            prefixHash.push_back(hash);
            p = (p * 31) % MOD;
        }
    }

    long long computeSubstringHash(int l, int r)
    {
        long long hash = prefixHash[r];
        if (l - 1 >= 0)
            hash = (hash - prefixHash[l - 1] + MOD) % MOD;

        hash = (hash * power(power(31, l, MOD), MOD - 2, MOD)) % MOD;
        return hash;
    }
};

int main()
{
    string s;
    cin >> s;

    prefixHashing ph(s);

    int q;
    cin >> q;
    while (q--)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int hash1 = ph.computeSubstringHash(l1, r1);
        int hash2 = ph.computeSubstringHash(l2, r2);

        if (hash1 == hash2)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}

/*
Tkae input string
queries in terms of l1 r1 l2 r2
check whether s[l1 ... r1] ans s[l2 ... r2] is equal or not
*/