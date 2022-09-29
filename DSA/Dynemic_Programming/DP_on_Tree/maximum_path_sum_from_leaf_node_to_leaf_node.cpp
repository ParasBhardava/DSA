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

    int temp = max(r, l) + root->data;
    if(root->left == NULL && root->right == NULL)
        temp = max(temp, root->data);

    int ans = max(temp, l + r + root->data);
    res = max(res, ans); 

    return temp;
}

int main()
{

    return 0;
}