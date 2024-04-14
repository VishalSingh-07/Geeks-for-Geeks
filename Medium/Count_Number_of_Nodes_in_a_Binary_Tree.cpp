/*
Count Number of Nodes in a Binary Tree

You are given the root of a complete binary tree. Your task is to find the count of nodes.

A complete binary tree is a binary tree whose, all levels except the last one are completely filled, the last level may or may not be completely filled and Nodes in the last level are as left as possible.

Design an algorithm that runs better than O(n).

Example:

Input: 
root = [1,2,3,4,5,6]
Output: 
6
Explanation: 
There are a total of 6 nodes in the given tree.


Your Task:
- Complete the function int cnt_nodes(Node *root), which takes the pointer of the root of the given Binary tree and returns the count of its number of nodes.

Expected Time Complexity: O((LogN)2).
Expected Auxiliary Space: O(Log N).

Constraints:

0 <= N (number of nodes) <= 5 * 104 
0 <= value of nodes <= 5 * 104

The tree is guaranteed to be complete.

 
*/
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node()
        : val(0)
        , left(nullptr)
        , right(nullptr) {}
    Node(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr) {}
    Node(int x, Node *left, Node *right)
        : val(x)
        , left(left)
        , right(right) {}
};


// } Driver Code Ends
// User function Template for C++


// Brute Force Approach
// Time complexity -> O(n) and Space -> O(h)
// where n: number of nodes in the binary tree and h: height of the tree
class Solution {
    void traversal(Node *root, int &count){
        if(root==nullptr){
            return;
        }
        count++;
        traversal(root->left,count);
        traversal(root->right,count);
    }
  public:
    int countNodes(Node* root) {
        // Write your code here
        if(root==nullptr){
            return 0;
        }
        int count=0;
        traversal(root,count);
        return count;
    }
};


// Optimized Approach
// Time complexity -> O((logn)^2) and Space -> O(logn)
// where n: number of nodes in the binary tree
class Solution {
    int findHeightLeft(Node* root){
        int height=0;
        while(root!=nullptr){
            height++;
            root=root->left;
        }
        return height;
    }
    int findHeightRight(Node* root){
        int height=0;
        while(root!=nullptr){
            height++;
            root=root->right;
        }
        return height;
    }
  public:
    int countNodes(Node* root) {
        // Base case: If the root is NULL, there are no nodes
        if(root==nullptr){
            return 0;
        }
        // Find the left height of the tree
        int lh=findHeightLeft(root);
        // Find the right height of the tree
        int rh=findHeightRight(root);

        // Check if the last level is completely filled
        if(lh==rh){

            // If so, use the formula for total nodes in a perfect
            // binary tree ie. 2^h - 1
            return (1<<lh)-1;
            // OR
            // return pow(2,lh)-1;
        }

        // If the last level is not completely filled, recursively count 
        // nodes in left and right subtrees
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};



//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        Node *root = new Node(v[0]);

        int count = 0;
        queue<Node *> q;
        q.push(root);
        Node *cur = NULL;
        for (int i = 1; i < v.size(); i++) {
            Node *node = new Node(v[i]);
            if (count == 0) {
                cur = q.front();
                q.pop();
            }
            if (count == 0) {
                count++;
                cur->left = node;
            } else {
                count = 0;
                cur->right = node;
            }
            if (v[i] >= 0) {
                q.push(node);
            }
        }

        Solution obj;
        cout << obj.countNodes(root) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends

/*
1. Question link -- https://www.geeksforgeeks.org/problems/count-number-of-nodes-in-a-binary-tree/1

2. Solution link -- https://leetcode.com/problems/count-complete-tree-nodes/solutions/5021572/2-approach-best-c-solution-brute-force-and-optimized-approach-with-explanation

3. Video Link -- https://youtu.be/u-yWemKGWO0
*/