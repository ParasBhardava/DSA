//  Also known as BFS Traversal

#include<bits/stdc++.h>
using namespace std;

struct Node
{
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

vector<vector<int>> printLevelOrder(Node * root)
{
    vector<vector<int>>ans;
    if(root == NULL)
        return ans;

    queue<Node *>q;
    q.push(root);
    
    while(!q.empty())
    {
        int size = q.size();
        vector<int>level;

        for(int i = 0; i<size; i++)
        {
            Node *node = q.front();
            q.pop();

            if(node->left != NULL)
                q.push(node->left);

            if(node->right != NULL)
                q.push(node->right);

            level.push_back(node->data);
        }

        ans.push_back(level);
    }

    return ans;       
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

    vector<vector<int>> levelOrder = printLevelOrder(root);

    for(int i = 0; i<levelOrder.size(); i++)
    {
        for(int j = 0; j<levelOrder[i].size(); j++)
        {
            cout << levelOrder[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}