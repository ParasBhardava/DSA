#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> solve(vector<pair<int, int>> &v, int k)
{
    priority_queue< pair<int, pair<int, int>> >maxHeap;     // priority_queue({distance, point})

    for(int i = 0; i<v.size(); i++)
    {
        maxHeap.push({v[i].first*v[i].first + v[i].second*v[i].second , v[i]});

        if(maxHeap.size() > k)
            maxHeap.pop();
    }

    vector<pair<int, int>>ans;
    while(!maxHeap.empty())
    {
        ans.push_back(maxHeap.top().second);
        maxHeap.pop();
    }
    
    return ans;
}

int main()
{
    vector<pair<int, int>> v{{3, 3}, {5, -1}, {-2, 4}};
    int k = 2;

    vector<pair<int, int>>ans = solve(v, k);
    for(auto i : ans)
        cout<<i.first<<" "<<i.second<<"\n";

    return 0;
}