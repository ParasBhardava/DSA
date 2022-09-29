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

bool isValidBST(Node * root, int minVal, int maxVal)
{
    if(root == NULL)
        return true;

    if(root->data >= maxVal || root->data <= minVal)
        return false;

    return isValidBST(root->left, minVal, root->data) && 
           isValidBST(root->right, root->data, maxVal);
    
}


int main()
{
    Node *root1 = new Node(5);
    root1->left = new Node(4);
    root1->right = new Node(7);
    root1->left->left = new Node(3);
    root1->right->left = new Node(6);

    cout<<isValidBST(root1, INT_MIN, INT_MAX)<<"\n";

    Node *root2 = new Node(8);
    root2->left = new Node(6);
    root2->right = new Node(12);
    root2->right->left = new Node(8);
    root2->right->right = new Node(15);
    cout<<isValidBST(root2, INT_MIN, INT_MAX)<<"\n";

    return 0;
}