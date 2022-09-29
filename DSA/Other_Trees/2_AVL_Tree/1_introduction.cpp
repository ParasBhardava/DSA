/*

AVL tree is a self-balancing Binary Search Tree (BST) where the difference between heights of left and right subtrees cannot be more than one for all nodes

Balance factor = hight of left subtree - highto of right subtree ---> {-1, 0, 1}
bf = abs(hl - hr) <= 1      --->    balanced
bf = abs(hl - hr)  > 1      --->    imsbalanced


Advantages :
Most of the BST operations (e.g., search, max, min, insert, delete.. etc) take O(h) time where h is the height of the BST. The cost of these operations may become O(n) for a skewed Binary tree. If we make sure that height of the tree remains O(Logn) after every insertion and deletion, then we can guarantee an upper bound of O(Logn) for all these operations. The height of an AVL tree is always O(Logn) where n is the number of nodes in the tree (See this video lecture for proof). 

*/

#include<bits/stdc++.h>
using namespace std;


