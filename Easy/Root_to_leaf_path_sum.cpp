/*
Root to leaf path sum

Given a binary tree and an integer target, check whether there is a root-to-leaf path with its sum as target.

Examples :

Input: tree = 1, target = 2
            /   \
          2     3
Output: false
Explanation: There is no root to leaf path with sum 2.


Input: tree = 1,  target = 4
            /   \
          2     3
Output: true
Explanation: The sum of path from leaf node 3 to root 1 is 4.



Expected Time Complexity: O(n)
Expected Auxiliary Space: O(height of tree)

Constraints:
- 1 ≤ number of nodes ≤ 104
- 1 ≤ target ≤ 106
*/


//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/*you are required to
complete this function */

// Optimized Approach
// Time complexity -> O(n) and Space -> O(height of tree)
class Solution {
    bool traversal(Node *root, int target, int sum){
        if(root==nullptr){
            return false;
        }
        sum+=root->data;
        if(root->left==nullptr && root->right==nullptr){
            return sum==target;
        }
        bool left=traversal(root->left,target,sum);
        bool right=traversal(root->right,target,sum);
        return left || right;
    }
  public:
    bool hasPathSum(Node *root, int target) {
        return traversal(root,target,0);
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        int sum;
        scanf("%d ", &sum);
        // if (sum == 2) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool r = ob.hasPathSum(root, sum);
        if (r)
            cout << "true"
                 << "\n";
        else
            cout << "false"
                 << "\n";
    }
    return 0;
}

// } Driver Code Ends


// Question link -- https://www.geeksforgeeks.org/problems/root-to-leaf-path-sum/1

