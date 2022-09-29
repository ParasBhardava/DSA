#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#include <iostream>

using namespace std;

void Merge(int arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low, temp[high + 1];

    while (i <= mid && j <= high)

    {

        if (arr[i] < arr[j])

        {

            temp[k] = arr[i];

            i++;

            k++;
        }

        else

        {

            temp[k] = arr[j];

            j++;

            k++;
        }
    }

    while (i <= mid)

    {

        temp[k] = arr[i];

        i++;

        k++;
    }

    while (j <= high)

    {

        temp[k] = arr[j];

        j++;

        k++;
    }

    for (int i = low; i <= high; i++)

    {

        arr[i] = temp[i];
    }
}

void MergeSort(int arr[], int low, int high)

{

    if (low < high)

    {

        int mid = (low + high) / 2;

        MergeSort(arr, low, mid);

        MergeSort(arr, mid + 1, high);

        Merge(arr, low, mid, high);
    }
}

int main()
{

    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)

        cin >> arr[i];

    MergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)

        cout << arr[i] << " ";

    return 0;
}
