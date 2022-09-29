#include <bits/stdc++.h>
using namespace std;

void waveSort(vector<int>&arr)
{
    int n = arr.size();
    for(int i = 1; i < n; i+=2)
    {
        if(arr[i] > arr[i-1])
            swap(arr[i], arr[i-1]);

        if(i <= n-2 && arr[i] > arr[i+1])
            swap(arr[i], arr[i+1]);
    }
}

int main()
{
    int n = 7;
    vector<int> arr{1, 3, 4, 7, 5, 6, 7};

    for (int i = 0; i < 7; i++)
        cout << arr[i] << " ";
    cout << "\n";

    waveSort(arr);

    for (int i = 0; i < 7; i++)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}