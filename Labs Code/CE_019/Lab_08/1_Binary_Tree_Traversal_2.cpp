#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL; 
        this->right = NULL;
    }
};

map <int,bool>node_present;

class Tree
{
public:
    Node *root = NULL;
    void insert(int data, int l, int r)
    {
        if(root == NULL)
        {
            if(l == data || r == data)
            {
                cout << "Tree can not contain loop";
                exit(0);
            }
            root = new Node(data);
            node_present[data] = true;
            if(l != 0)
            {
                root->left = new Node(l);
                node_present[l] = true;
            }
            if(r != 0)
            {
                root->right = new Node(r);
                node_present[r] = true;
            }
            return;
        }
        else
            search_and_insert(data,root,l,r);
    }
    
    void preorder(Node *root)
    {
        if(root == NULL)
            return;
        
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    
    void inorder(Node *root)
    {
        if(root == NULL)
            return;
        
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
        
    }
    
    void postorder(Node *root)
    {
        if(root == NULL)
            return;
            
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
    
    void search_and_insert(int data, Node *n,int l,int r)
    {
        if(n == NULL)
            return;
        if(n->data == data)
        {
            if(l == data || r == data)
            {
                cout << "Tree can not contain loop";
                exit(0);
            }
            if(l != 0)
            {
                if(node_present[l] != true)
                {
                    n->left = new Node(l);
                    node_present[l] = true;
                } 
                else
                {
                    cout << "Left node is already a child node";
                    exit(0);
                }
            }
            if(r != 0)
            {
                if(node_present[r] != true)
                {
                    n->right = new Node(r);
                    node_present[r] = true;
                } 
                else
                {
                    cout << "Right node is already a child node";
                    exit(0);
                }
            }
            return;
        }
        search_and_insert(data,n->left,l,r);
        search_and_insert(data,n->right,l,r); 
    }
};

int main() 
{
    int n, data, left, right;
    cin >> n;
    Tree tree;
    
    for(int i=0;i<n;i++)
    {
        cin >> data >> left >> right;
        tree.insert(data, left, right);
    }
    
    tree.preorder(tree.root);
    cout<<"\n";
    tree.inorder(tree.root);
    cout<<"\n";
    tree.postorder(tree.root);
    return 0;
}