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

Node * treeConstructInPost(vector<int>&inorder, int instart, int inend, 
            vector<int>&postorder, int poststart, int postend, unordered_map<int, int>&mp)
{

    if(instart > inend || poststart > postend)
        return NULL;

    Node *root = new Node(postorder[postend]);
    int inRoot = mp[postorder[postend]];
    int numLeft = inRoot - instart;

    root->left = treeConstructInPost(inorder, instart, inRoot-1,
                                           postorder, poststart, poststart+numLeft-1, mp);

    root->right = treeConstructInPost(inorder, inRoot+1, inend, 
                                     postorder, poststart+numLeft, postend-1, mp);

    return root;
}

Node * constructTree(vector<int>&inorder, vector<int>&postorder)
{
    if(inorder.size() != postorder.size())
        return NULL;
        
    unordered_map<int, int>mp;
    for(int i = 0; i<inorder.size(); i++)
        mp[inorder[i]] = i;

    return treeConstructInPost(inorder, 0, inorder.size()-1,
             postorder, 0, postorder.size()-1, mp);
    
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
    int n = 5;
    vector<int>postorder{4, 2, 5, 3, 1};
    vector<int>inorder{4, 2, 1, 5, 3};

    Node *root = constructTree(inorder, postorder);
    inorderPrint(root);

    return 0;
}