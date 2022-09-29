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

vector<int> getPostorder(Node * root)
{
    vector<int>res;
    Node *curr = root;

    while(curr !=  NULL)
    {
        if(curr->right == NULL)
        {
            res.push_back(curr->data);
            curr = curr->left;
        }

        else
        {
            Node *prev = curr->right;
            while(prev->left != NULL && prev->left != curr)
                prev = prev->left;

            if(prev->left == NULL)
            {
                prev->left = curr;
                res.push_back(curr->data);
                curr = curr->right;
            }

            else
            {
                prev->left = NULL;
                curr = curr->left;
            }
        }
    }

    reverse(res.begin(), res.end());
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

    vector<int>postorder = getPostorder(root);
    for(int i : postorder)
        cout<<i<<" ";
    cout<<"\n";

    return 0;
}