#include<iostream>
#include<vector>

using namespace std;

void print(vector<int>&v)
{
    cout<<"Size : "<<v.size()<<"\n";
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>v;

    for(int i=0; i<n; i++)
    {
        int m;
        cin>>m;
        vector<int>temp;
        // v.push_back(vector<int>());
        for(int j=0; j<m; j++)
        {
            int x;
            cin>>x;
            temp.push_back(x);
            // v[i].push_back(x);
        }
        v.push_back(temp);
    }

    for(int i=0; i<v.size(); i++)
    {
        print(v[i]);
    }

    return 0;
}