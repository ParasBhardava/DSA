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

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(4);
    

    return 0;
}
    /*
              1
            /   \
           2     3
         /   \
        4     5
      
    */

/*
Properties Of Binary Trees :

1. Maximum Nodes At level L is 2^L (L =0, 1, 2, 3 ....)
2. Maximum Nodesin a tree of height H is 2^H-1
3. For N nodes, minimum possible height or minimum numbe of levels are log2(N+1)
4. A binary tree with L leaves has at least log2(N+1) + 1 number of levels


*/