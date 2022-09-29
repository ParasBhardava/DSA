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
        this->left = NULL;
        this->right = NULL;
    } 
};

Node *build(vector<int>&preorder, int &i, int bound)
{
    if(i >= preorder.size() || preorder[i] >= bound)
        return NULL;

    Node *root = new Node(preorder[i++]);
    root->left = build(preorder, i, root->data);
    root->right = build(preorder, i, bound);

    return root;
}

Node * BSTfromPreorder(vector<int>&preorder)
{
    int i = 0;
    return build(preorder, i, INT_MAX);
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        cout << "BST is empty !";
        return;
    }

    if (root->left)
        inorder(root->left);

    cout << root->data << " ";

    if (root->right)
        inorder(root->right);
}

int main()
{
    vector<int>preorder{8,5,1,7,10,12};
    Node *root = BSTfromPreorder(preorder);
    inorder(root);

    return 0;
}

// Tme complexity : O(3N);
// space complexity : O(N);