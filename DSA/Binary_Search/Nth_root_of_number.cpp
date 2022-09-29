#include<bits/stdc++.h>
using namespace std;

double eps = 1e-6;

double multiply(double a, int n)
{
    double ans = 1;
    for(int i=0; i<n; i++)
    {
         ans = ans*a;
    }
    return ans;
}

int main()
{
    double x, n;
    cin>>x>>n;
    double left = 1, right = x, mid;

    while(right - left > eps)
    {
        mid = (left+right)/2;
        if(multiply(mid, n)< x)
            left = mid;

        else
            right = mid;
    }

    cout<<left<<" "<<right<<"\n"; 

    return 0;
}

// Time Complexity :
// sqrt : log(n*10^d)
// nth root : p * log(n*10^d)