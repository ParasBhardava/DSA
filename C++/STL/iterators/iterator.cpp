#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int>v1 = {1, 2, 3, 4, 5};
    vector<int> :: iterator it;
    for(it = v1.begin(); it != v1.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<"\n";

    vector<pair<int, int>>vp = {{1, 2}, {2, 3}, {3, 4}};
    vector<pair<int, int>>::iterator vp_it;
    for(vp_it = vp.begin(); vp_it != vp.end(); vp_it++)
    {
        cout<<(*vp_it).first<<" "<<(*vp_it).second<<"\n";
        // cout<<vp_it->first<<" "<<vp_it->second<<"\n";
    }
    return 0;
}

/*

Difference between it++ and it+1

it++ = next iterator
it+1 = next location

For linear container both it++ and it+1 are same
For Nonlinear container it+1  give compilation error and it++ give next iterator and work fine

*/