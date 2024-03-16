/*
Symmetric Tree

Given a Binary Tree. Check whether it is Symmetric or not, i.e. whether the binary tree is a Mirror image of itself or not.

Example 1:

Input:
         5
       /   \
      1     1
     /       \
    2         2
Output: 
True
Explanation: 
Tree is mirror image of itself i.e. tree is symmetric


Example 2:

Input:
         5
       /   \
      10     10
     /  \     \
    20  20     30
Output: 
False


Your Task:
You don't need to read input or print anything. Your task is to complete the function isSymmetric() which takes the root of the Binary Tree as its input and returns True if the given Binary Tree is the same as the Mirror image of itself. Else, it returns False.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
0<=N<=105
*/

//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

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
/*
Structure of the node of the tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/


// Optimized Approach [Recursive Approach]
// Time complexity -> O(n) and Space -> O(n)
class Solution{
    bool isSymmetricHelper(struct Node* leftTree, struct Node* rightTree){
    if(leftTree==nullptr || rightTree==nullptr){
        return leftTree==rightTree;
    }
    if(leftTree->data!=rightTree->data){
        return false;
    }
    return isSymmetricHelper(leftTree->left,rightTree->right)
        &&  isSymmetricHelper(leftTree->right,rightTree->left);
    }
    public:
    // return true/false denoting whether the tree is Symmetric or not
    bool isSymmetric(struct Node* root)
    {
	    return root==nullptr || isSymmetricHelper(root->left,root->right);
    }
};



// Optimized Approach [Iterative Approach]
// Time complexity -> O(n) and Space -> O(n)
class Solution{
    public:
    // return true/false denoting whether the tree is Symmetric or not
    bool isSymmetric(struct Node* root)
    {
	    queue<struct Node*> q;
        q.push(root);
        q.push(root);
        while(!q.empty()){
            struct Node *leftNode=q.front();
            q.pop();
            struct Node *rightNode=q.front();
            q.pop();

            if(leftNode==nullptr && rightNode==nullptr){
                continue;
            }
            if(leftNode==nullptr || rightNode==nullptr){
                return false;
            }
            if(leftNode->data!=rightNode->data){
                return false;
            }
            q.push(leftNode->left);
            q.push(rightNode->right);
            q.push(leftNode->right);
            q.push(rightNode->left);
        }
        return true;
    }
};






//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);

        vector<int> ans;
        Solution ob;
        if(ob.isSymmetric(root)){
            cout<<"True"<<endl;
        }
        else{ 
            cout<<"False"<<endl;
        }
    }
    return 0;
}

// } Driver Code Ends

/*
1. Question link -- https://www.geeksforgeeks.org/problems/symmetric-tree/1

2. Solution Link -- https://leetcode.com/problems/symmetric-tree/solutions/4884765/easy-c-solution-optimized-approach-iterative-and-recursive-with-explanation

3. Video Link -- https://youtu.be/nKggNAiEpBE

*/