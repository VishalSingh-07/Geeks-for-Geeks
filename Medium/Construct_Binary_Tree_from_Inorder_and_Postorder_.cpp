/*
Construct Binary Tree from Inorder and Postorder

Given inorder and postorder traversals of a binary tree(having n nodes) in the arrays in[] and post[] respectively. The task is to construct a binary tree from these traversals.

Driver code will print the preorder traversal of the constructed tree.

Example 1:

Input:
n = 8
in[] = {4, 8, 2, 5, 1, 6, 3, 7}
post[] = {8, 4, 5, 2, 6, 7, 3, 1}
Output: 
1 2 4 8 5 3 6 7
Explanation: 
For the given postorder and inorder traversal of tree the  resultant binary tree will be
          1
       /      \
     2        3
   /  \      /  \
  4   5    6   7
   \
    8



Example 2:

Input:
n = 5
in[] = {9, 5, 2, 3, 4}
post[] = {5, 9, 3, 4, 2}
Output: 
2 9 5 4 3
Explanation:  
The  resultant binary tree will be
           2
        /     \
       9      4
        \     /
         5   3


Your Task:
- You do not need to read input or print anything. Complete the function buildTree() which takes the inorder, postorder traversals and the number of nodes in the tree as input parameters and returns the root node of the newly constructed Binary Tree.

Expected Time Complexity: O(n^2)
Expected Auxiliary Space: O(n)

Constraints:
1 <= n <= 103
1 <= in[i], post[i] <= 106
*/
//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

/*
Optimized Approach
Time complexity -> O(n) and Space -> O(n)
where:
- n: number of nodes in a binary tree
- is: inorderStart
- ie: inorderEnd
- ps: postorderStart
- pe: postorderEnd
*/

class Solution
{
    Node *constructBinaryTree(int inorder[],int is, int ie, int postorder[],int ps,int pe, map<int,int> &mpp){
        if(ps>pe || is>ie){
            return nullptr;
        }
        Node *root=new Node(postorder[pe]);
        int inRoot=mpp[postorder[pe]];
        int numsLeft=inRoot-is;
        root->left=constructBinaryTree(inorder,is,inRoot-1,postorder,ps,ps+numsLeft-1,mpp);
        root->right=constructBinaryTree(inorder,inRoot+1,ie,postorder,ps+numsLeft,pe-1,mpp);
        return root;
    }
    public:
    //Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int in[], int post[], int n) {
        // Your code here
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[in[i]]=i;
        }
        return constructBinaryTree(in,0,n-1,post,0,n-1,mpp);
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

/*
1. Question link -- https://www.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1

2. Solution Link -- https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/solutions/5112274/optimized-approach-with-detailed-explanation-best-c-solution-striver-solution

3. Video Link -- https://youtu.be/LgLRTaEMRVc?si=sLowSLnvSjB2WAm2
*/