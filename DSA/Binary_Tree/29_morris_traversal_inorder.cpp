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

vector<int> getInorder(Node * root)
{
    vector<int>res;
    Node *curr = root;

    while(curr !=  NULL)
    {
        if(curr->left == NULL)
        {
            res.push_back(curr->data);
            curr = curr->right;
        }

        else
        {
            Node *prev = curr->left;
            while(prev->right != NULL && prev->right != curr)
                prev = prev->right;

            if(prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }

            else
            {
                prev->right = NULL;
                res.push_back(curr->data);
                curr = curr->right;
            }
        }
    }

    return res;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);

    vector<int>inorder = getInorder(root);
    for(int i : inorder)
        cout<<i<<" ";
    cout<<"\n";

    return 0;
}