/*
Nodes at given distance in binary tree

Given a binary tree, a target node in the binary tree, and an integer value k, find all the nodes that are at distance k from the given target node. No parent pointers are available.
Note:

You have to return the list in sorted order.
The tree will not contain duplicate values.
Example 1:

Input:      
          20
        /    \
      8       22 
    /   \
   4    12 
       /   \
      10    14
Target Node = 8
K = 2
Output: 10 14 22
Explanation: The three nodes at distance 2
from node 8 are 10, 14, 22.

Example 2:

Input:      
         20
       /    \
      7      24
    /   \
   4     3
        /  
       1    
Target Node = 7
K = 2
Output: 1 24


Your Task:  
- You don't need to read input or print anything. Complete the function KDistanceNodes() which takes the root of the tree, target, and K as input parameters and returns a list of nodes at k distance from target in a sorted order.

Expected Time Complexity: O(N*logN)
Expected Auxiliary Space: O(Height of tree)

Constraints:
- 1 ≤ N ≤ 105
- 1 ≤ data of node ≤ 109
- 1 ≤ target ≤ 109
- 1 ≤ k ≤ 20
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

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
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

// Optimized Approach
// Time complexity -> O(nlogn) and Space -> O(n)
class Solution
{
private:
    vector<int> findDistance(unordered_map<Node*,Node*> &parentTrack, Node *start, int k){
        queue<Node*> q;
        q.push(start);
        unordered_map<Node*,int> visited;
        visited[start]=1;
        int distance=0;
        while(!q.empty()){
            int sz=q.size();
            if(distance==k){
                break;
            }
            distance++;
            for(int i=0;i<sz;i++){
                Node *node=q.front();
                q.pop();
                
                if(node->left!=nullptr && !visited[node->left]){
                    visited[node->left]=1;
                    q.push(node->left);
                }
                if(node->right!=nullptr && !visited[node->right]){
                    visited[node->right]=1;
                    q.push(node->right);
                }
                if(parentTrack[node] && !visited[parentTrack[node]]){
                    visited[parentTrack[node]]=1;
                    q.push(parentTrack[node]);
                }
            }
        }
        vector<int> res;
        while(!q.empty()){
            Node *curr=q.front();
            q.pop();
            res.push_back(curr->data);
        }
        sort(res.begin(),res.end());
        return res;
    }
    Node *markParent(Node *root, unordered_map<Node*,Node*> &parentTrack, int target){
        queue<Node*> q;
        q.push(root);
        Node *res;
        while(!q.empty()){
            Node *node=q.front();
            q.pop();
            if(node->data==target){
                res=node;
            }
            if(node->left!=nullptr){
                parentTrack[node->left]=node;
                q.push(node->left);
            }
            if(node->right!=nullptr){
                parentTrack[node->right]=node;
                q.push(node->right);
            }
        }
        return res;
    }
public:

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        unordered_map<Node*,Node*> parentTrack;
        Node *start=markParent(root,parentTrack,target);
        return findDistance(parentTrack,start,k);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends

/*
1. Question link -- https://www.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1

2. Solution link -- https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/solutions/5179862/optimized-approach-with-explanation-best-c-solution-beats-100-00-of-users-with-c

3. Video link -- https://youtu.be/i9ORlEy6EsI?si=K_optysQriHMKIMD
*/