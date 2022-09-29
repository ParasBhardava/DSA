#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class SimpleArray
{
    int size;
    int *arr;

public:
    SimpleArray(int n)
    {
        size = n;
        arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            int element;
            cin >> element;
            arr[i] = element;
        }
    }

    ~SimpleArray()
    {
        cout << "destructor called\n";
        delete[] arr;
    }

    void operator+(SimpleArray const &ref)
    {
        if (ref.size == size)
        {
            for (int i = 0; i < size; i++)
            {
                arr[i] += ref.arr[i];
            }
        }

        else
            return;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    int n1, n2;
    cin >> n1;
    SimpleArray simple_array_1(n1);
    cin >> n2;
    SimpleArray simple_array_2(n2);

    simple_array_1 + simple_array_2;

    simple_array_1.print();

    return 0;
}