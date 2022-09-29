#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>

using namespace std;

bool nextPermutation(string s[], int n)
{
    if(n == 1)
        return false;

    int peak = -1, i = 1;

    while(i<n)
    {
        if(s[i] > s[i-1])
        {
            peak = i;
        }
        i++;
    }

    if(peak == -1)
        return false;

    int index = peak;
    for(i = peak; i<n; i++)
    {
        if(s[i] > s[peak-1] && s[i] < s[index])
            index = i; 
    }

    swap(s[peak-1], s[index]);
    sort(s+peak, s+n);

    return true;
}

int main()
{
    int n;
    cout<<"Enter Number: ";
    cin>>n;

    string str[n];
    for(int i=0; i<n; i++)
    {
        cin>>str[i];
    }
    cout<<"\n";

    int j = 1;
    do{
        cout<<j<<" ";
        for(int i=0; i<n; i++)
            cout<<str[i]<<" ";
        j++;
        cout<<"\n";
    }while(nextPermutation(str, n));

    return 0;
}