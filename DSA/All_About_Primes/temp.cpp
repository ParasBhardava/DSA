#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int i = 0;
        while (n)
        {
            if (n & 1)
            {
                cout << i << "\n";
                break;
            }

            i++;
            n >>= 1;
        }
    }

    return 0;
}