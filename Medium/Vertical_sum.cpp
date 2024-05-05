/*
Vertical sum

Given a binary tree having n nodes, find the vertical sum of the nodes that are in the same vertical line. Return all sums through different vertical lines starting from the left-most vertical line to the right-most vertical line.

Example 1:

Input:
       1
    /    \
  2      3
 /  \    /  \
4   5  6   7
Output: 
4 2 12 3 7
Explanation:
The tree has 5 vertical lines
Line 1 has only one node 4 => vertical sum is 4.
Line 2 has only one node 2 => vertical sum is 2.
Line-3 has three nodes: 1,5,6 => vertical sum is 1+5+6 = 12.
Line-4 has only one node 3 => vertical sum is 3.
Line-5 has only one node 7 => vertical sum is 7.



Example 2:

Input:
          1
         /
        2
       /
      3
     /
    4
   /
  6
 /
7
Output: 
7 6 5 4 3 2 1
Explanation:
There are seven vertical lines each having one node.


Your Task:
- You don't need to take input. Just complete the function verticalSum() that takes root node of the tree as parameter and returns an array containing the vertical sum of tree from left to right.

Expected Time Complexity: O(nlogn).
Expected Auxiliary Space: O(n).

Constraints:
- 1<=n<=104
- 1<= Node value <= 105
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
/*Complete the function below
Node is as follows:
struct Node{
int data;
Node *left,*right;
};
*/

// Optimized Approach
// Time complexity -> O(nlogn) and Space -> O(n)
class Solution{
  public:
    vector <int> verticalSum(Node *root) {
        // add code here.
        vector<int> ans;
        if(root==nullptr){
            return ans;
        }
        queue<pair<Node*, int>> q;
        map<int,multiset<int>> mpp;
        q.push({root,0});
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            Node* node=it.first;
            int vertical=it.second;
            mpp[vertical].insert(node->data);
            if(node->left!=nullptr){
                q.push({node->left,vertical-1});
            }
            if(node->right!=nullptr){
                q.push({node->right,vertical+1});
            }
        }
        for (const auto& pair : mpp) {
            int sum=0;
            for (const auto& value : pair.second) {
                sum+=value;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};


// OR

class Solution{
  public:
    vector <int> verticalSum(Node *root) {
        // add code here.
        vector<int> ans;
        if(root==nullptr){
            return ans;
        }
        queue<pair<Node*, int>> q;
        map<int,int> mpp;
        q.push({root,0});
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            Node* node=it.first;
            int vertical=it.second;
            mpp[vertical]+=node->data;
            if(node->left!=nullptr){
                q.push({node->left,vertical-1});
            }
            if(node->right!=nullptr){
                q.push({node->right,vertical+1});
            }
        }
        for (const auto& it : mpp) {
            ans.push_back(it.second);
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
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        Solution obj;
        vector <int> res = obj.verticalSum(root);
        for (int i : res) cout << i << " ";
        cout<<endl;
    }
}
// } Driver Code Ends

/*
1. Question link -- https://www.geeksforgeeks.org/problems/vertical-sum/1

2. Reference Solution link -- https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/solutions/4876004/beats-100-00-of-users-with-c-easy-c-solution-optimized-approach-with-explanation
*/