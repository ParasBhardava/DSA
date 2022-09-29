#include <bits/stdc++.h>
using namespace std;

void printInBinary(int num)
{
    int n = CHAR_BIT*sizeof(num);
    stack<bool> s;
    for (int i=1; i<=n; i++)
    {
        s.push(num%2);
        num = num/2; 
    }     
    
    for (int i=1; i<=n; i++)
    {
        cout << s.top();
        s.pop();
          
        // Put a space after every byte. 
        if (i % CHAR_BIT == 0)
        cout << " "; 
    }
}

int main()
{
    int num = 3;
    printInBinary(num);
    return 0;
}