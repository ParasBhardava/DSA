#include<bits/stdc++.h>
using namespace std;

struct item
{
    int value;
    int weight;
};

bool compare(item a, item b)
{
    double r1 = (double)a.value/a.weight;
    double r2 = (double)b.value/b.weight;

    return r1 > r2;
}

double fractionalKnapsack(item arr[], int W, int n)
{
    sort(arr, arr+n, compare);

    int currWeight = 0;
    double ans = 0;

    for(int i = 0; i < n; i++)
    {
        if(currWeight + arr[i].weight <= W)
        {
            currWeight += arr[i].weight;
            ans += arr[i].value;
        }

        else
        {
            int remain = W - currWeight;
            ans += (double)(arr[i].value/ arr[i].weight) * (double)remain;
            break;
        }
    }

    return ans;
}

int main()
{
    int n = 3;    
    int value[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int W = 50;

    struct item arr[n];
    for(int i = 0; i < n; i++)
    {
        arr[i].value = value[i];
        arr[i].weight = weight[i];
    }

    cout<<fractionalKnapsack(arr, W, n);
    return 0;
}