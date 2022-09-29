#include<iostream>
#include<vector>

using namespace std;

void print(vector<pair<int, int>>&v)
{
    cout<<"Size : "<<v.size()<<"\n";
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }
}

int main()
{
    // vector<pair<int, int>>v1 {{1, 2}, {4, 5}, {6, 7}};
    // print(v1);

    int n = 5;
    vector<pair<int, int>>v2;
    for(int i=0; i<n; i++)
    {
        int x, y;
        cin>>x>>y;
        v2.push_back({x, y});   // v2.push_back(make_pair(x, y));
    }
    print(v2);


    return 0;
}