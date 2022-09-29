#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

vector<vector<int>> verticalTraversal(Node *root)
{
    vector<vector<int>> res;

    if (root == NULL)
    {
        cout<<"Tree is empty !\n";
        return res;
    }

    map<int, map<int, multiset<int>>> mp;
    queue<pair<Node *, pair<int, int>>> q;

    q.push({root, {0, 0}});
    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node *node = it.first;
        int line = it.second.first;
        int level = it.second.second;

        mp[line][level].insert(node->data);
        
        if(node->left != NULL)
            q.push({node->left, {line-1, level+1}});

        if(node->right != NULL)
            q.push({node->right, {line+1, level+1}});
    }

    for(auto p : mp)
    {
        vector<int>column;
        for(auto q : p.second)
        {
            column.insert(column.end(), q.second.begin(), q.second.end());
        }
        res.push_back(column);
    }

    return res;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right->left = new Node(9);
    root->right->right = new Node(10);

    vector<vector<int>>res = verticalTraversal(root);
    for(int i = 0; i<res.size(); i++)
    {
        for(int j = 0; j<res[i].size(); j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<"\n";
    }


    return 0;
}
