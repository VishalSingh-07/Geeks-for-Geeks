/*
K distance from root

Given a binary tree having n nodes and an integer k. Print all nodes that are at distance k from the root (root is considered at distance 0 from itself). Nodes should be printed from left to right.

Example 1:

Input:
k = 0
      1
    /   \
   3     2
Output: 
1
Explanation: 
1 is the only node which is 0 distance from the root 1.


Example 2:

Input:
k = 3
        1
       /
      2
       \
        1
      /  \
     5    3
Output: 
5 3
Explanation:  
5 and 3 are the nodes which are at distance 3 from the root 3.
Here, returning 3 5 will be incorrect.

Your Task:
- You don't have to take input. Complete the function Kdistance() that accepts root node and k as parameters and returns the value of the nodes that are at a distance k from the root.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
- 1 <= n <= 104
- 0 <= k <= 30
*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
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
/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */



// Optimized Approach [Using Inorder Traversal]
// Time complexity -> O(n) and Space -> O(h)
// where n: number of nodes in a binary tree and h: height of the tree
class Solution
{
    void traverse(struct Node *root, int k, int x, vector<int> &ans){
        if(root==nullptr){
            return;
        }
        traverse(root->left,k,x+1,ans);
        if(x==k){
            ans.push_back(root->data);
        }
        traverse(root->right,k,x+1,ans);
    }
    public:
    // function should print the nodes at k distance from root
    vector<int> Kdistance(struct Node *root, int k)
    {
      // Your code here
      vector<int> ans;
      traverse(root,k,0,ans);
      return ans;
    }
};



// Optimized Approach (Using Level Order Traversal)
// Time complexity -> O(n) and Space -> O(h)
class Solution
{
    public:
    // function should print the nodes at k distance from root
    vector<int> Kdistance(struct Node *root, int k)
    {
      
      queue<Node*> q;
      q.push(root);
      int level=0;
      while(level!=k){
          level++;
          int n=q.size();
          while(n--){
              Node *node=q.front();
              q.pop();
              if(node->left!=nullptr){
                  q.push(node->left);
              }
              if(node->right!=nullptr){
                  q.push(node->right);
              }
          }
      }
      vector<int> ans;
      while(!q.empty()){
          ans.push_back(q.front()->data);
          q.pop();
      }
      return ans;
    }
};





//{ Driver Code Starts.

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        int k;
		scanf("%d ",&k);
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        Solution obj;
        vector<int> vec = obj.Kdistance(root, k);
        for(int i = 0;i<vec.size();i++){
            cout<<vec[i]<<" ";
        }
        cout<<endl;
    }
    return 1;
}
// } Driver Code Ends

// Question link -- https://www.geeksforgeeks.org/problems/k-distance-from-root/1