#include <bits/stdc++.h>
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

int maxWidth(Node *root)
{
    if (root == NULL)
        return 0;

    int ans = 0;
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        int size = q.size();
        int min = q.front().second;
        int first, last;
        
        for (int i = 0; i < size; i++)
        {
            Node *node = q.front().first;
            int cur_id = q.front().second - min;
            q.pop();

            if (i == 0)
                first = cur_id;
            
            if (i == size - 1)
                last = cur_id;
            
            if (node->left != NULL)
                q.push({node->left, cur_id * 2 + 1});
            
            if (node->right != NULL)
                q.push({node->right, cur_id * 2 + 2});
        }

        ans = max(ans, last - first + 1);
    }
    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);

    cout << maxWidth(root) << "\n";

    return 0;
}

// Width : no. of nodes in a level between any two nodes