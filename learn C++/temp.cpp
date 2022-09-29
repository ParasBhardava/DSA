#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        int maximum = 0;
        int minimum = 1000000001;
        int ans = 0;
        
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            maximum = max(maximum, arr[i]);
            minimum = min(minimum, arr[i]);
        }
        
        for(int i=0; i<n; i++)
        {
            if(arr[i] == maximum)
            {
                arr[i] = minimum;
                break;
            }
        }
        
        for(int i=0; i<n; i++)
        {
            ans += arr[i]/minimum;
        }
        
        cout<<ans<<"\n";
    }
	return 0;
}
