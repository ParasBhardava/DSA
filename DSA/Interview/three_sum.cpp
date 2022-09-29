#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>>res;

    for(int i = 0; i<arr.size()-2; i++)
    {
        if(i == 0 || (i > 0 && arr[i] != arr[i-1]))
        {
            int low = i+1, high = arr.size()-1, sum = 0 - arr[i];

            while(low < high)
            {
                if(arr[low] + arr[high] == sum)
                {
                    vector<int>temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[low]);
                    temp.push_back(arr[high]);
                    res.push_back(temp);

                    while(low < high && arr[low] == arr[low+1])
                        low++;

                    while(low < high && arr[high] == arr[high-1])
                        high--;

                    low++;
                    high--;
                }

                else if(arr[low] + arr[high] < sum)
                    low++;

                else
                    high--;
            }
        }
    }

    return res;

}


int main()
{
    vector<int>arr{-1, 0, 1, 2, -1, -4};

    vector<vector<int>>res = solve(arr);

    for(int i = 0; i<res.size(); i++)
        cout<<res[i][0]<<" "<<res[i][1]<<" "<<res[i][2]<<"\n";

    return 0;
}

// a + b + c = 0