// Binary serach are used in Monotonic Data
// Monotonic function : Which maintain a given order

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5, k = 4;
    int arr[n] = {1, 2, 3, 4, 5};

    int left = 0, right = n - 1, mid;
    while (right - left > 1)
    {
        mid = (left + right) / 2;

        if (arr[mid] < k)
            left = mid + 1;

        else
            right = mid;
    }

    if (arr[left] == k)
        cout << left << "\n";

    else if (arr[right] == k)
        cout << right << "\n";

    else    
        cout << "Not Found\n";
}