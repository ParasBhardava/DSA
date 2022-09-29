#include <bits/stdc++.h>
using namespace std;

const int n = 2e7; // size must be constant
int arr[n];

int main()
{

    arr[n - 1] = 10000;
    cout << arr[n - 1] << "\n";

    // int n1 = 1e7;
    // int arr1[n1];
    // arr1[n1-1] = 10;
    // printf("%d", arr1[n1-1]);

    int n2 = 1e5;
    int arr2[n2];
    arr2[n2 - 1] = 10;
    cout << arr2[n2 - 1] << "\n";

    // bool array limit locally : 1e6
    // bool array limit globally : 1e8

    return 0;
}

// generally locally declared arry size is 1e5. If size is greater then programm will terminate or give segmentation fault.
// IF size is very large then we declare array globally