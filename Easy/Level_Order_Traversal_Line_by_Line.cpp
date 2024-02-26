/*
Level order traversal Line by Line

Given a Binary Tree, your task is to find its level order traversal.
For the below tree the output will be 1 $ 2 3 $ 4 5 6 7 $ 8 $.

Return the level order traversal line by line.

          1
       /     \
     2        3
   /    \     /   \
  4     5   6    7
    \
     8


Example 1:

Input:
          1
        /
       4
     /   \
    4     2

Output:1 $ 4 $ 4 2 $


Example 2:

Input:
            10
          /    \
        20      30
     /     \
    40     60

Output: 10 $ 20 30 $ 40 60 $


Your Task:
This is a function problem. You don't need to read input. Just complete the function levelOrder() that takes nodes as parameter and returns level order traversal as a 2D list.

Note: The driver code prints the levels '$' separated.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of edges <= 1000
0 <= Data of a node <= 100
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
vector<vector<int>> levelOrder(struct Node* node);

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


int main() {
    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);

        vector<vector<int>> vec = levelOrder(root);
        for(vector<int> v : vec){
            for(int value : v){
                cout<<value<<" ";
            }
            cout<<"$ ";
        }
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends


/* A binary tree Node

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

//Function to return the level order traversal line by line of a tree.

// Optimized Approach
// Time complexity -> O(n) and Space -> O(n)
vector<vector<int>> levelOrder(Node* node)
{
    //Your code here
    vector<vector<int>> ans;
    queue<Node*> q;
    q.push(node);
    while(!q.empty())
    {
        int s=q.size();
        vector<int> temp;
        for(int i=0;i<s;i++)
        {
            node=q.front();
            q.pop();
            if(node->left!=nullptr)
            {
                q.push(node->left);
            }
            if(node->right!=nullptr)
            {
                q.push(node->right);
            }
            temp.push_back(node->data);
        }
        ans.push_back(temp);
    }
    return ans;
}


// Question link -- https://www.geeksforgeeks.org/problems/level-order-traversal-line-by-line/1

