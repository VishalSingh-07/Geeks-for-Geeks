/*
Vertical Traversal of Binary Tree

Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

Example 1:

Input:
           1
         /   \
       2       3
     /   \   /   \
   4      5 6      7
              \      \
               8      9           
Output: 
4 2 1 5 6 3 8 7 9 



Example 2:

Input:
       1
    /    \
   2       3
 /    \      \
4      5      6
Output: 4 2 1 5 3 6


Your Task:
You don't need to read input or print anything. Your task is to complete the function verticalOrder() which takes the root node as input parameter and returns an array containing the vertical order traversal of the tree from the leftmost to the rightmost level. If 2 nodes lie in the same vertical level, they should be printed in the order they appear in the level order traversal of the tree.

Expected Time Complexity: O(N*log(N))
Expected Auxiliary Space: O(N)

Constraints:
1 <= Number of nodes <= 3*104
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

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;
        
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}


// } Driver Code Ends

// Optimized Approach
// Time complexity -> O(nlogn) and Space -> O(n)
// where n: number of nodes in a binary tree
/*
Remember :
1. For left child -> {vertical-1,level+1}
2. For right child -> {vertical+1,level+1}

// where vertical: columns and level: rows


    This int is for storing verticals
     ^
     |
map<int,map<int,multiset<int>>> mpp:

    
        This int is for level 
         ^
         |
    map<int,multiset<int>>
                |
                This multiset is used for multinode on same level as well as same vertical
   
*/

class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        	// Write your code here.
        vector<int> ans;
        if(root==nullptr){
            return ans;
        }
        map<int,map<int,vector<int>>> mpp;
        queue<pair<Node*,pair<int,int>>> q;
        q.push({root,{0,0}}); // q.push({root,{verticals,levels}})
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            Node* node=it.first;
            int vertical=it.second.first,level=it.second.second;
            mpp[vertical][level].push_back(node->data);
            if(node->left!=nullptr){
                q.push({node->left,{vertical-1,level+1}});
            }
            if(node->right!=nullptr){
                q.push({node->right,{vertical+1,level+1}});
            }
        }
        // where p.first=int and p.second=map<int,multiset<int>>
        for(auto p: mpp){
            for(auto q: p.second){
                // q.first -> int and q.second -> multiset<int>
                for(auto k: q.second){
                    ans.push_back(k);
                }
            }
        }
        return ans; 
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        // string c;
        // getline(cin,c);
        Solution obj;
    	Node* root = buildTree(s);
    	
    	vector <int> res = obj.verticalOrder(root);
    	for (int i : res) cout << i << " ";
        cout << endl;
    }
	return 0;
}



// } Driver Code Ends

/*
1. Question link -- https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

2. Solution Link -- https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/solutions/4876004/beats-100-00-of-users-with-c-easy-c-solution-optimized-approach-with-explanation

3. Video Link -- https://youtu.be/q_a6lpbKJdw
*/