/*
Serialize and deserialize a binary tree

Serialization is to store a tree in an array so that it can be later restored and deserialization is reading tree back from the array. Complete the functions

serialize() : stores the tree into an array a and returns the array.
deSerialize() : deserializes the array to the tree and returns the root of the tree.
Note: Multiple nodes can have the same data and the node values are always positive integers. Your code will be correct if the tree returned by deSerialize(serialize(input_tree)) is same as the input tree. Driver code will print the in-order traversal of the tree returned by deSerialize(serialize(input_tree)).

Example 1:

Input:
      1
    /   \
   2     3
Output: 
2 1 3


Example 2:

Input:
         10
       /    \
      20    30
    /   \
   40  60
Output: 
40 20 60 10 30

Your Task:
- The task is to complete two functions serialize which takes the root node of the tree as input and stores the tree into an array and deSerialize which deserializes the array to the original tree and returns the root of it.

Expected Time Complexity: O(Number of nodes).
Expected Auxiliary Space: O(Number of nodes).

Constraints:
1 <= Number of nodes <= 104
1 <= Data of a node <= 109


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
/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */


/*
Optimized Approach
Time Complexity: O(n)
- serialize function: O(n), where N is the number of nodes in the tree. This is because 
the function performs a level-order traversal of the tree, visiting each node once.

- deserialize function: O(N), where N is the number of nodes in the tree. 
Similar to the serialize function, it processes each node once while reconstructing the tree.

Space Complexity: O(N)
- serialize function: O(N), where N is the maximum number of nodes at any level in the tree. 
In the worst case, the queue can hold all nodes at the last level of the tree.

- deserialize function: O(N), where N is the maximum number of nodes at any level in the tree. 
The queue is used to store nodes during the reconstruction process, and in the worst case, it may hold all nodes at the last level.
*/
 

class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        //Your code here
        if(root==nullptr){
            return {0};
        }
        vector<int> ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* currNode=q.front();
            q.pop();
            
            if(currNode==nullptr){
                ans.push_back(-1);
            }else{
                ans.push_back(currNode->data);   
            }
            
            if(currNode!=nullptr){
                q.push(currNode->left);
                q.push(currNode->right);
            }
        }
        return ans;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &arr)
    {
       //Your code here
       if(arr.size()==0){
           return nullptr;
       }
       
       int i=0;
       Node *root=new Node(arr[i]);
       queue<Node*> q;
       q.push(root);
       
       while(!q.empty()){
           Node *currNode=q.front();
           q.pop();
           
           i++;
           if(arr[i]==-1){
               currNode->left==nullptr;
           }else{
              Node *leftNode=new Node(arr[i]); 
              currNode->left=leftNode;
              q.push(leftNode);
           }
           
            i++;
           if(arr[i]==-1){
               currNode->right==nullptr;
           }else{
              Node *rightNode=new Node(arr[i]); 
              currNode->right=rightNode;
              q.push(rightNode);
           }
       }
       return root;
    }

};

//{ Driver Code Starts.

void inorder(Node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void _deleteTree(Node* node)  
{  
    if (node == NULL) return;  
  
    /* first delete both subtrees */
    _deleteTree(node->left);  
    _deleteTree(node->right);  
  
    /* then delete the node */
    //cout << "Deleting node: " << node->data << endl;  
    delete node;  
}  
  
/* Deletes a tree and sets the root as NULL */
void deleteTree(Node** node_ref)  
{  
    _deleteTree(*node_ref);  
    *node_ref = NULL;  
}  

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        
        Solution serial, deserial;
        vector<int> A = serial.serialize(root);
        Node* temp = root;
        deleteTree(&root);
        Node *getRoot = deserial.deSerialize(A);
        inorder(getRoot);
        
        cout << "\n";

    }


    return 0;
}
// } Driver Code Ends


/*
1. Question link -- https://www.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1

2. Solution link -- https://leetcode.com/problems/serialize-and-deserialize-binary-tree/solutions/5101078/optimized-approach-with-explanation-best-c-solution-striver-solutio

3. Video link -- https://youtu.be/-YbXySKJsX8
*/