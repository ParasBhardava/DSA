// Given an array of jobs where every job has a deadline and associated profit if the job is finished before the deadline. It is also given that every job takes a single unit of time, so the minimum possible deadline for any job is 1. How to maximize total profit if only one job can be scheduled at a time.

#include <bits/stdc++.h>
using namespace std;

struct Job
{
   int id;     
   int deadline;    
   int profit;  
};

bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}

pair<int, int> jobSheduling(Job arr[], int n)
{
    sort(arr, arr+n, compare);
    int maxi = arr[0].deadline;
    for(int i = 1; i<n; i++)
        maxi = max(maxi, arr[i].deadline);

    int slot[maxi + 1];

    for(int i = 0; i <=maxi; i++)
        slot[i] = -1;

    int countJob = 0, jobProfit = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = arr[i].deadline; j > 0; j--)
        {
            if(slot[j] == -1)
            {
                slot[j] = arr[i].id;
                countJob++;
                jobProfit += arr[i].profit;
                break;
            }
        }
    }

    for(int i = 0; i <= maxi; i++)
    {
        if(slot[i] != -1)
            cout<<slot[i]<<" ";
    }
    cout<<"\n";

    return make_pair(countJob, jobProfit);
}

int main()
{
    int n = 5;
    Job arr[] = {{1, 2, 100}, {1, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15}};

    pair<int, int>ans = jobSheduling(arr, n);
    cout<<"count of Jobs: "<<ans.first<<"\n";
    cout<<"Job Profit: "<<ans.second<<"\n";

    return 0;
}