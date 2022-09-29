/*

Construction of Segment Tree from given array

We start with a segment arr[0 . . . n-1]. and every time we divide the current segment into two halves(if it has not yet become a segment of length 1), and then call the same procedure on both halves, and for each such segment, we store the sum in the corresponding node.

All levels of the constructed segment tree will be completely filled except the last level. Also, the tree will be a Full Binary Tree because we always divide segments in two halves at every level. Since the constructed tree is always a full binary tree with n leaves, there will be n-1 internal nodes. So the total number of nodes will be 2*n – 1. Note that this does not include dummy nodes.


What is the total size of the array representing segment tree?

If n is a power of 2, then there are no dummy nodes. So the size of the segment tree is 2n-1 (n leaf nodes and n-1 internal nodes). If n is not a power of 2, then the size of the tree will be 2*x – 1 where x is the smallest power of 2 greater than n. For example, when n = 10, then size of array representing segment tree is 2*16-1 = 31.

An alternate explanation for size is based on heignt. Height of the segment tree will be ⌈log₂n⌉. Since the tree is represented using array and relation between parent and child indexes must be maintained, size of memory allocated for segment tree will be 2 * 2⌈log2n⌉  – 1.

it is also well to take size 4*n

Use Case :
- Point update
- Range sum, min, max queries
- Range update
*/