#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

int solve(Node * root, int &res)
{
    if(root == NULL)
        return 0;

    int l = solve(root->left, res);
    int r = solve(root->right, res);

    int temp = max(r, l) + 1;
    int ans = max(temp, l+r+1);
    res = max(res, ans);

    return temp;
}

int main()
{

    return 0;
}