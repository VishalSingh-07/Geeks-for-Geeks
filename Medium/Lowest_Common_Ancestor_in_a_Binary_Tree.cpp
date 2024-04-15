/*
Lowest Common Ancestor in a Binary Tree

Given a Binary Tree with all unique values and two nodes value, n1 and n2. The task is to find the lowest common ancestor of the given two nodes. We may assume that either both n1 and n2 are present in the tree or none of them are present.

LCA: It is the first common ancestor of both the nodes n1 and n2 from bottom of tree.

Example 1:

Input:
n1 = 2 , n2 = 3  
       1 
      / \ 
     2   3
Output: 1
Explanation:
LCA of 2 and 3 is 1.


Example 2:
Input:
n1 = 3 , n2 = 4
           5    
          /    
         2  
        / \  
       3   4
Output: 2
Explanation:
LCA of 3 and 4 is 2. 


Example 3:
Input:
n1 = 5 , n2 = 4
           5    
          /    
         2  
        / \  
       3   4
Output: 5
Explanation:
LCA of 5 and 4 is 5. 


Your Task:
- You don't have to read, input, or print anything. Your task is to complete the function lca() that takes nodes, n1, and n2 as parameters and returns the LCA node as output. 

Expected Time Complexity:O(N).
Expected Auxiliary Space:O(Height of Tree).

Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 105
*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(){
        data = 0;
        left = right = NULL;
    }
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

// } Driver Code Ends
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// Brute Force Appproach
// Time complexity -> O(2*n) and Space -> O(2*h)
// where n: number of nodes in a binary tree and h: height of the binary tree
class Solution
{
     // Helper function to find the path from root to a given node
    bool getPath(Node *root, vector<Node*> &path, int target) {
        // Base case: if root is null, return false as we've reached the end
        if (root == nullptr) {
            return false;
        }
        
        // Add current node to the path
        path.push_back(root);

        // If the current node is the target, return true to indicate we've found the path
        if (root->data == target) {
            return true;
        }
        
        // Recursively search in left and right subtrees
        if (getPath(root->left, path, target) || getPath(root->right, path, target)) {
            return true; // Return true if target found in either subtree
        }
        
        // If target is not found in the subtree rooted at current node, backtrack
        path.pop_back();
        return false;
    }
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        // Paths to store the nodes from root to n1 and n2
        vector<Node*> pathToN1, pathToN2;
        
        // Find paths from root to n1 and n2
        getPath(root, pathToN1, n1);
        getPath(root, pathToN2, n2);

        // Traverse both paths simultaneously to find the lowest common ancestor
        Node *lca = nullptr;
        int i = 0, j = 0;
        while (i < pathToN1.size() && j < pathToN2.size()) {
            if (pathToN1[i] == pathToN2[j]) {
                lca = pathToN1[i]; // Update lowest common ancestor
            } else {
                break; // Stop traversal if nodes diverge
            }
            i++;
            j++;
        }
        
        return lca;
    }
};


// Optimized Appproach
// Time complexity -> O(n) and Space -> O(h)
// where n: number of nodes in a binary tree and h: height of the binary tree
class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        if(root==nullptr || root->data==n1 || root->data==n2){
            return root;
        }
        
        Node* left=lca(root->left,n1,n2);
        Node* right=lca(root->right,n1,n2);
        
        if(left==nullptr){
            return right;
        }
        else if(right==nullptr){
            return left;
        }
        //both left and right are not null, we found our result
        else{
            return root;
        }
    }
};




//{ Driver Code Starts.

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

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
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

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d %d ",&a,&b);
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        Solution ob;
        cout<<ob.lca(root,a,b)->data<<endl;
    }
    return 0;
}

// } Driver Code Ends

/*
1. Question link -- https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1

2. Solution link -- https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/solutions/5028379/2-approach-best-c-solution-brute-force-optimized-approach-with-explanation

3. Video link -- https://youtu.be/_-QHfMDde90
*/