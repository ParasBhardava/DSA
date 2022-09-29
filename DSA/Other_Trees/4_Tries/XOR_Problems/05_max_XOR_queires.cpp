/*
Problem statement :

You are given an array ‘arr’ consisting of ‘n’ non-negative integers. You are also given a list ‘queries’ consisting of ‘m’ queries, where the ‘i-th’ query is a array of two non-negative integers ‘xi’, ‘ai’, i.e ‘queries[i]’ = [‘xi’, ‘ai’].
The answer to the ith query, i.e ‘queries[i]’ is the maximum bitwise xor value of ‘xi’ with any integer less than or equal to ‘ai’ in ‘arr’.
You should return an array consisting of ‘n’ integers where the ‘i-th’ integer is the answer of ‘queries[i]’.

*/

#include<bits/stdc++.h>
using namespace std;

class Trie
{
    struct Trienode
    {
        Trienode *child[2];
    };

    Trienode *root;

    Trienode *getNode()
    {
        Trienode *newnode = new Trienode;
        newnode->child[0] = NULL;
        newnode->child[1] = NULL;

        return newnode;
    }

    public:
    Trie()
    {
        root = getNode();
    }


    void insert(int num)
    {
        Trienode *curr = root;
        int bit;
        for(int i = 31; i >=0; i--)
        {
            bit = (num >> i) & 1;
            if(curr->child[bit] == NULL)
                curr->child[bit] = getNode();

            curr = curr->child[bit];
        }
    }

    int getMax(int num)
    {
        int maxNum = 0;
        Trienode *curr = root;
        int bit;
        
        for(int i = 31; i >= 0; i--)
        {
            bit = (num >> i) & 1;
            
            if(curr->child[1-bit] != NULL)
            {
                maxNum |= (1 << i);
                curr = curr->child[1-bit];
            }

            else
            {
                curr = curr->child[bit]; 
            }
        }

        return maxNum;
    }
};

int main()
{

    // Given
    int n = 5, m = 2;
    vector<int>arr{0, 1, 2, 3, 4};
    vector<vector<int>>queries{{1, 3}, {5, 6}};

    // start
    Trie *t = new Trie();
    
    sort(arr.begin(), arr.end());
    
    vector<pair<pair<int, int>, int>>offlineQueries;
    for(int i = 0; i < m; i++)
    {
        offlineQueries.push_back({{queries[i][1], queries[i][0]}, i});
    }
    sort(offlineQueries.begin(), offlineQueries.end());
    
    vector<int>ans(m, 0);
    
    int idx = 0;
    for(int i = 0; i < m; i++)
    {
        int ai = offlineQueries[i].first.first;
        int xi = offlineQueries[i].first.second;
        int queryIdx = offlineQueries[i].second;

        while (idx < n && arr[idx] <= ai)
        {
            t->insert(arr[idx]);
            idx++;
        }

        if(idx == 0)
            ans[queryIdx] = -1;

        else
            ans[queryIdx] = t->getMax(xi);

    }

    for(int &i : ans)
        cout<<i<<" ";

    return 0;
}

// Time Complexity: O(q * 32 + n * 32)   --->   O((n + q) * 32)