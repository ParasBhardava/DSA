// balenced binary tree : the diffence of left tree and right tree is less than or equal to 1

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

int dfsHeight(Node *root)
{
    if (root == NULL)
        return 0;

    int leftHeight = dfsHeight(root->left);
    if (leftHeight == -1)
        return -1;

    int righttHeight = dfsHeight(root->right);
    if (righttHeight == -1)
        return -1;

    if(abs(leftHeight-righttHeight) > 1)
        return -1;

    return 1 + max(leftHeight, righttHeight);
}

bool isBalanced(Node *root)
{
    return dfsHeight(root) != -1;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int height = 0;
    if (isBalanced(root))
        cout << "Balanced Tree\n";
    else
        cout << "Unbalanced Tree\n";

    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->left->left = new Node(3);

    if (isBalanced(root2))
        cout << "Balanced Tree\n";
    else
        cout << "Unbalanced Tree\n";

    return 0;
}

// spcae complexity = O(n)
// time complexity = O(n)