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

void markParents(Node *root, unordered_map<Node *, Node *>&mp)
{
    if(root == NULL)
        return;

    queue<Node*>q;
    q.push(root);

    while(!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        if(curr->left)
        {
            mp[curr->left] = curr;
            q.push(curr->left);
        }

        if(curr->right)
        {
            mp[curr->right] = curr;
            q.push(curr->right);
        }
    }
}

vector<int>  distanceK(Node *root, Node *target, int k)
{
    unordered_map<Node*, Node*>mp;
    markParents(root, mp);

    unordered_map<Node*, bool>visited;
    queue<Node *>q;

    q.push(target);
    visited[target] = true;
    int currLevel = 0;

    while(!q.empty())
    {
        int size = q.size();
        if(currLevel == k)
            break;
        currLevel++;

        for(int i = 0; i<size; i++)
        {
            Node *curr = q.front();
            q.pop();

            if(curr->left && !visited[curr->left])
            {
                q.push(curr->left);
                visited[curr->left] = true;
            }

            if(curr->right && !visited[curr->right])
            {
                q.push(curr->right);
                visited[curr->right] = true;
            }

            if(mp[curr] && !visited[mp[curr]])
            {
                q.push(mp[curr]);
                visited[mp[curr]] = true;
            }
        }

    }

    vector<int>res;
    while(!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        res.push_back(curr->data);
    }

    return res;
}

int main()
{
    Node *root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);
    root->right->left = new Node(0);
    root->right->right = new Node(8);

    vector<int>res = distanceK(root, root->left, 2);
    for(int i : res)
        cout<<i<<" ";
    cout<<"\n";

    return 0;
}
