#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val = 0)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *constructTreeInPre(vector<int>&inorder, int instart, int inend, 
                        vector<int>&preorder, int prestart, int preend, unordered_map<int, int>&mp)
{
    if(instart > inend || prestart > preend)
        return NULL;

    Node *root = new Node(preorder[prestart]);
    int inRoot = mp[preorder[prestart]];
    int numLeft = inRoot-instart;

    root->left = constructTreeInPre(inorder, instart, inRoot-1, preorder, prestart+1, prestart+numLeft, mp);
    root->right = constructTreeInPre(inorder, inRoot+1, inend, preorder, prestart+numLeft+1, preend, mp);

    return root;
}

Node * constructTree(vector<int>&inorder, vector<int>&preorder)
{
    if(inorder.size() != preorder.size())
        return NULL;

    unordered_map<int, int>mp;
    for(int i = 0; i<inorder.size(); i++)
        mp[inorder[i]] = i;

    return constructTreeInPre(inorder, 0, inorder.size()-1, preorder, 0, preorder.size()-1, mp);  

}

void inorderPrint(Node *root)
{
    if(root == NULL)
        cout<<"Tree is empty !\n";

    if(root->left)
        inorderPrint(root->left);
    
    cout<<root->data<<" ";
    
    if(root->right)
        inorderPrint(root->right);

}

int main()
{
    vector<int>inorder{9, 3, 15, 20, 7};
    vector<int>preorder{3, 9, 20, 15, 7};

    Node *root = constructTree(inorder, preorder);
    inorderPrint(root);

    return 0;
}