#include <iostream>
#include <string>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::string;

template <typename T>
void sort(T arr[], int n)
{
    T temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

template <typename t>
void print(t arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{

    int int_arr[10] = {9, 8, 1, 2, 6, 5, 4, 3, 0, 7};
    sort(int_arr, 10);
    print(int_arr, 10);

    float float_arr[6] = {9.1, 8.2, 8.3, 7.7, 9.9, 9.1};
    sort(float_arr, 6);
    print(float_arr, 6);

    string str_arr[3] = {string("XYZ"), string("ABC"), string("PQR")};
    sort(str_arr, 3);
    print(str_arr, 3);

    return 0;
}