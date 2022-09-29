#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>v = {1, 3, 2, 4};
    vector<int>ans;
    stack<int>st;

    for(int i=0; i<v.size(); i++)
    {
        if(st.size() == 0)
            ans.push_back(-1);

        else if(st.size()>0 && st.top()<v[i])
            ans.push_back(st.top());

        else if(st.size() > 0 && st.top() >= v[i])
        {
            while(st.size() > 0 && st.top() >= v[i])
            {
                st.pop();
            }

            if(st.size() == 0)
                ans.push_back(-1);
            
            else
                ans.push_back(st.top());
        }

        st.push(v[i]);

    }

    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";

    return 0;
}

