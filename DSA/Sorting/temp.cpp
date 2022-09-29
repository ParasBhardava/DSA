#include <bits/stdc++.h>
using namespace std;

long int swaps = 0, comparisons = 0;
int partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int i = start - 1;

    for (int j = start; j < end; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[j], arr[i]);\
            swaps++;
        }
        comparisons++;
    }
    swap(arr[i + 1], arr[end]);
    swaps++;
    return i + 1;
}

void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int pivot = partition(arr, start, end);
        quickSort(arr, start, pivot - 1);
        quickSort(arr, pivot + 1, end);
    }
}

void print(int arr[], int n)
{
    if (n < 10)
    {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
    cout << "Total Comparison: " << comparisons <<"\n";
    cout << "Total Swapping: " << swaps <<"\n";
    comparisons = 0;
    swaps = 0;
}

int main()
{
    int arrSorted[5] = {1, 2, 3, 4, 5};
    int arrUnsorted[5] = {5, 4, 3, 2, 1};
    int random[5] = {3, 1, 5, 4, 2};
    int arr1000[1000], arr10000[10000], arr100000[100000];


    for (int i = 0; i < 1000; i++)
        arr1000[i] = rand();
    for (int i = 0; i < 10000; i++)
        arr10000[i] = rand();
    for (int i = 0; i < 100000; i++)
        arr100000[i] = rand();

    quickSort(arrSorted, 0, 4);
    cout << "\n--------------------For Sorted Array----------------------\n";
    print(arrSorted, 5);

    cout << "\n--------------------For UnSorted Array--------------------\n";
    quickSort(arrUnsorted, 0, 4);
    print(arrUnsorted, 5);

    cout << "\n--------------------For Random Array----------------------\n";
    quickSort(random, 0, 4);
    print(random, 5);

    cout << "\n--------------------1000 Input----------------------------\n";
    quickSort(arr1000, 0, 999);
    print(arr1000, 1000);

    cout << "\n--------------------10000 Input---------------------------\n";
    quickSort(arr10000, 0, 9999);
    print(arr10000, 10000);

    cout << "\n--------------------100000 Input--------------------------\n";
    quickSort(arr100000, 0, 99999);
    print(arr100000, 100000);

    return 0;
}