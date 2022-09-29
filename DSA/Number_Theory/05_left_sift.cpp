#include<bits/stdc++.h>

int main()
{
    std::cout<<sizeof(int)<<"\n";
    std::cout<<INT_MAX<<"\n";
    int a = (1LL<<31)-1;
    std::cout<<a;
    return 0;
}

// Imprtant Note : 1 << n = 2^n
// a << n = a * 2^n;
// a >> n = a / 2^n;