#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;


    Node(int val)
    {
        this->data = val;
        this->right = NULL;
        this->left = NULL;
    }
};

class NodeValue
{
    public :
    int maxNode, minNode, maxSize;
    
    NodeValue(int maxNode, int minNode, int maxSize)
    {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }

};

// Postorder Traversal
NodeValue solve(Node *root)
{
    // An empty tree is BST of size 0
    if(root == NULL)
        return NodeValue(INT_MIN, INT_MAX, 0);

    // Get values from left and right subtree of current tree
    auto left = solve(root->left);
    auto right = solve(root->right);

    // Current node is greater than max in left AND smaller than min in right. It is a BST 
    if(left.maxNode < root->data && root->data < right.minNode)
    {
        return NodeValue(max(root->data, right.maxNode), min(root->data, left.minNode), 1 + left.maxSize + right.maxSize);
    }

    // Otherwise, return [INF, -INF] so that parent can't be valid BST
    return NodeValue(INT_MAX, INT_MIN, max(left.maxSize, right.maxSize));

}

int main()
{
    Node *root = new Node(20);
    root->left = new Node(15);
    root->right = new Node(40);
    root->left->left = new Node(14);
    root->left->right = new Node(18);
    root->right->left = new Node(30);
    root->right->right = new Node(60);
    root->left->left->right = new Node(17);
    root->left->right->left = new Node(16);
    root->left->right->right = new Node(19);
    root->right->right->left = new Node(50);

    cout<<solve(root).maxSize;

    return 0;
}

// Time Complexity : O(N)
// Space Complexity : O(1)