#include<bits/stdc++.h>
using namespace std;

bool isPerfect(long long int n)
{
	long long int sum = 1;

	for (long long int i=2; i*i<=n; i++)
	{
		if (n%i==0)
		{
			if(i*i!=n)
				sum = sum + i + n/i;
			else
				sum=sum+i;
		}
	}

	if (sum == n && n != 1)
		return true;

	return false;
}

int solve(int arr[], int k, int n)
{

    for(int i = 0; i < n; i++)
    {
        if(isPerfect(arr[i]))
            arr[i] = 1;

        else
            arr[i]= 0;
    }

    int i = 0, j = 0, mx = INT_MIN, sum = 0;
    while(j < n)
    {
        sum += arr[j];

        if(j-i+1 < k)
            j++;

        else if(j-i+1 == k)
        {
            mx = max(mx, sum);
            sum -= arr[i];
            i++;
            j++;
        }
    }

    return mx;
}

int main()
{
    int n = 8;
    int arr[] = {28, 2, 3, 6, 496, 99, 8128, 24};
    int k = 4;
    cout<<solve(arr, k, n)<<"\n";
    return 0;
}