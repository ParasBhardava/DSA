#include<bits/stdc++.h>
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

int solve(Node *node, int &pathSum)
{
    if(node == NULL)
        return 0;

    int leftSum = max(0, solve(node->left, pathSum));
    int rightSum = max(0, solve(node->right, pathSum));

    pathSum = max(pathSum, leftSum + rightSum + node->data);

    return node->data + max(leftSum, rightSum);
}

int maxPathSum(Node *root)
{
    int pathSum = INT_MIN;
    solve(root, pathSum);
    return pathSum;
}


int main()
{
    Node *root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    cout<<maxPathSum(root)<<"\n";

    return 0;
}