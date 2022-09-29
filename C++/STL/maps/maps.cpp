#include<iostream>
#include<map>

using namespace std;


void print(map<int, string>& m)
{
    cout<<"size : "<<m.size()<<"\n";
    for(auto &pr : m)
    {
        cout<<pr.first<<" "<<pr.second<<"\n";
            // O(logn) : access element
    }
    cout<<"\n";
}

int main()
{
    map<int, string>m;
    m[1] = "abc";        // O(logn) -> n=current size of map
    m[4] = "pqr";
    m[2] = "xyz";
    m.insert({7, "mno"});
    m.insert(make_pair(6, "fgg"));
    m[4] = "ddo";       // every key in map is unique

    m.erase(4);          // O(logn)
    auto it  = m.find(10);

    if(it != m.end())
       m.erase(it);
    
    // m.clear();
    
    print(m);

    // auto it  = m.find(2);       // O(logn)
    // if(it == m.end())
    // {
    //     cout<<"No Values"<<"\n";
    // }

    // else
    // {
    //     cout<<it->first<<" "<<it->second<<"\n";
    // }

    return 0;
} 