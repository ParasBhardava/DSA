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

string serialize(Node *root)
{
    if(root == NULL)
        return "";

    string s = "";
    queue<Node *>q;
    q.push(root);

    while(!q.empty())
    {
        Node * currNode = q.front();
        q.pop();
        if(currNode == NULL)
            s.append("#,");

        else
            s.append(to_string(currNode->data) + ',');

        if(currNode != NULL)
        {
            q.push(currNode->left);
            q.push(currNode->right);
        }

    }

    if(!s.empty() && s.at(s.size()-1) == ',')
        s.pop_back();

    return s;

}

Node *deserialize(string s)
{
    if(s.size() == 0)
        return NULL;

    stringstream ss(s);
    string str;
    getline(ss, str, ',');

    Node *root = new Node(stoi(str));
    queue<Node *>q;
    q.push(root);

    while(!q.empty())
    {
        Node *node = q.front();
        q.pop();

        getline(ss, str, ',');
        if(str == "#")
            node->left = NULL;

        else
        {
            Node * leftNode = new Node(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }

        getline(ss, str, ',');
        if(str == "#")
            node->right = NULL;

        else
        {
            Node * rightNode = new Node(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }

    return root;
}

void printLevelOrder(Node * root)
{
    if(root == NULL)
    {
        cout<<"Tree is empty !\n";
        return;
    }

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

            cout<<node->data<<" ";
        }

    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(13);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    string ser = serialize(root);
    cout<<ser<<"\n";

    Node *deser = deserialize(ser);
    printLevelOrder(deser);

    return 0;
}