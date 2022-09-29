// diameter : lonest path between two nodes 
// path does not need to pass through root

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

int height(Node *root, int &diameter)
{
    if(root == NULL)
        return 0;

    int leftHeight = height(root->left, diameter);
    int rightHeight = height(root->right, diameter);
    diameter = max(diameter, leftHeight + rightHeight);

    return 1+max(leftHeight, rightHeight);
}

int diameter(Node *root)
{
    int dia = 0;
    height(root, dia);
    return dia;
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
    cout<<diameter(root)<<"\n";

    return 0;
}
