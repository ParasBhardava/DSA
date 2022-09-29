#include <iostream>
using namespace std;

int main()
{
    int n, num, ans = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        ans ^= num;
    }

    cout << ans;

    return 0;
}