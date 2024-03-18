/*
Boundary Traversal of binary tree

Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.
Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Example 1:

Input:
        1 
      /   \
     2     3  
    / \   / \ 
   4   5 6   7
      / \
     8   9
   
Output: 1 2 4 8 9 6 7 3
 

Example 2:

Input:
            1
           /
          2
        /  \
       4    9
     /  \    \
    6    5    3
             /  \
            7     8

Output: 1 2 4 6 5 7 8


Your Task:
This is a function problem. You don't have to take input. Just complete the function boundary() that takes the root node as input and returns an array containing the boundary values in anti-clockwise.

Expected Time Complexity: O(N). 
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 105


*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Optimized Approach
// Time complexity -> O(n) and Space -> O(n)
// where n: number of nodes in a binary tree
class Solution {
    
    // Helper function to check if a given node is a leaf node
    bool isLeafNode(Node* root) {
        if (root->left == nullptr && root->right == nullptr) {
            return true;
        }
        return false;
    }

    // Helper function to add the left boundary nodes to the answer vector
    void addLeftBoundary(Node* root, vector<int>& ans) {
        Node* curr = root->left;
        while (curr != nullptr) {
            // Add non-leaf nodes to the answer vector
            if (!isLeafNode(curr)) {
                ans.push_back(curr->data);
            }
            // Traverse to the left child if it exists
            if (curr->left != nullptr) {
                curr = curr->left;
            } else {
                // Otherwise, go to the right child
                curr = curr->right;
            }
        }
    }

    // Helper function to add the leaf nodes to the answer vector
    void addLeafNodes(Node* root, vector<int>& ans) {
        if (isLeafNode(root)) {
            // If the current node is a leaf, add it to the answer vector
            ans.push_back(root->data);
            return;
        }
        // Recursively traverse left subtree
        if (root->left != nullptr) {
            addLeafNodes(root->left, ans);
        }
        // Recursively traverse right subtree
        if (root->right != nullptr) {
            addLeafNodes(root->right, ans);
        }
    }

    // Helper function to add the right boundary nodes to the answer vector
    void addRightBoundary(Node* root, vector<int>& ans) {
        Node* curr = root->right;
        vector<int> temp;
        while (curr != nullptr) {
            // Add non-leaf nodes to the temporary vector
            if (!isLeafNode(curr)) {
                temp.push_back(curr->data);
            }
            // Traverse to the right child if it exists
            if (curr->right != nullptr) {
                curr = curr->right;
            } else {
                // Otherwise, go to the left child
                curr = curr->left;
            }
        }
        // Add the elements from the temporary vector to the answer vector in reverse order
        for (int i = temp.size() - 1; i >= 0; i--) {
            ans.push_back(temp[i]);
        }
    }

public:
    // Main function to return the boundary nodes of a binary tree
    vector<int> boundary(Node* root) {
        // Initialize the answer vector
        vector<int> ans;
        
        // If the tree is empty, return empty vector
        if (root == nullptr) {
            return ans;
        }
        
        // Add the root node if it's not a leaf node
        if (!isLeafNode(root)) {
            ans.push_back(root->data);
        }
        // Add the left boundary nodes
        addLeftBoundary(root, ans);
        
        // Add the leaf nodes
        addLeafNodes(root, ans);
        
        // Add the right boundary nodes
        addRightBoundary(root, ans);
        
        return ans;
    }
};


//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

/*
1. Question link -- https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

2. Video link -- https://youtu.be/0ca1nvR0be4
*/