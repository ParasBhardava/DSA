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

int findMaxDistance(Node *target, unordered_map<Node *, Node *>parent)
{
    queue<Node*>q;
    q.push(target);
    map<Node*, bool>visited;
    visited[target] = true;
    int maxi = 0;

    while(!q.empty())
    {
        int size = q.size();
        int fl = 0;

        for(int i = 0; i<size; i++)
        {
            Node *node = q.front();
            q.pop();

            if(node->left && !visited[node->left])
            {
                fl = 1;
                visited[node->left] = true;
                q.push(node->left);
            }

            if(node->right && !visited[node->right])
            {
                fl = 1;
                visited[node->right] = true;
                q.push(node->right);
            }

            if(parent[node] && !visited[parent[node]])
            {
                fl = 1;
                visited[parent[node]] = true;
                q.push(parent[node]);
            }
        }

        if(fl)
            maxi++;
    }
    return maxi;
}

Node * bfsToMapParents(Node *root, unordered_map<Node*, Node*>&parent, int start)
{
    queue<Node *>q;
    q.push(root);
    Node *res;

    while(!q.empty())
    {
        Node *node = q.front();
        q.pop();
        
        if(node->data == start)
            res = node;
        
        if(node->left)
        {
            parent[node->left] = node;
            q.push(node->left);
        }

        if(node->right)
        {
            parent[node->right] = node;
            q.push(node->right);
        }
    }

    return res;
}

int timeToBurnTree(Node *root, int start)
{
    unordered_map<Node*, Node*>parent;
    Node *target = bfsToMapParents(root, parent, start); 
    int maxi = findMaxDistance(target, parent);
    return maxi;
}

int main()
{
    Node *root = new Node(1);
    root->left =  new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->right = new Node(7);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    cout<<timeToBurnTree(root, 2)<<"\n";

    return 0;
}