/*
Flatten binary tree to linked list

Given the root of a binary tree, flatten the tree into a "lLinked list":

The "linked list" should use the same Node class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
Example 1:

Input : 
          1
        /   \
       2     5
      / \     \
     3   4     6
Output :
1 2 3 4 5 6 
Explanation: 
After flattening, the tree looks 
like this
    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6 
Here, left of each node points 
to NULL and right contains the 
next node in preorder.The inorder 
traversal of this flattened tree 
is 1 2 3 4 5 6.


Example 2:

Input :
        1
       / \
      3   4
         /
        2
         \
          5 
Output : 
1 3 4 2 5  
Explanation : 
After flattening, the tree looks 
like this 
     1
      \
       3
        \
         4
          \
           2
            \ 
             5 
Here, left of each node points 
to NULL and right contains the 
next node in preorder.The inorder 
traversal of this flattened tree 
is 1 3 4 2 5.


Your task:
- You don't have to read input or print anything. Your task is to complete the function flatten() which takes the root of the tree and flattens the tree into a linked list without using any auxiliary space.


Note: The driver code prints the in-order traversal of the flattened binary tree.
 
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)
 
Constraints :
1<=n<=10^5
*/


//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	Node *left, *right;
};

/* utility that allocates a new Node
   with the given key  */
Node* newNode(int key)
{
	Node* node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	return (node);
}

Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

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
		if (i >= ip.size())
			break;
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

void inorder(struct Node* root)
{
	// base condition
	if (root == NULL)
		return;
	inorder(root->left);
	cout << root->key << " ";
	inorder(root->right);
}


// } Driver Code Ends
//User function Template for C++

// Brute Force Approach [Recursive Approach]
// Time complexity -> O(n) and Space -> O(n)
// where n: number of nodes in a binary tree
class Solution
{
    Node* prev=nullptr;
    public:
    void flatten(Node *root)
    {
        //code here
        if (root == nullptr) {
            return;
        }
        flatten(root->right);
        flatten(root->left);

        root->right=prev;
        root->left=nullptr;
        prev=root;
    }
};


// Better Approach [Using Stack]
// Time complexity -> O(n) and Space -> O(n)
class Solution
{
    public:
    void flatten(Node *root)
    {
        //code here
        if (root == nullptr) {
            return;
        }
        stack<Node*> st;
        st.push(root);
        while(!st.empty()){
            Node *curr=st.top();
            st.pop();
            if(curr->right!=nullptr){
                st.push(curr->right);
            }
            if(curr->left!=nullptr){
                st.push(curr->left);
            }
            if(!st.empty()){
                curr->right=st.top();
            }
            curr->left=nullptr;
        }
    }
};


// Optimized Approach [Morris Preorder Traversal]
// Time complexity -> O(n) and Space -> O(1)
class Solution
{
    public:
    void flatten(Node *root)
    {
        //code here
        if (root == nullptr) {
            return;
        }
        Node *curr=root;
        while(curr!=nullptr){
            if(curr->left!=nullptr){
                Node *prev=curr->left;
                while(prev->right!=nullptr){
                    prev=prev->right;
                }
                prev->right=curr->right;
                curr->right=curr->left;
                curr->left=nullptr;
            }
            curr=curr->right;
        }
    }
};




//{ Driver Code Starts.
int main() {

    int t;
	cin >> t;
	getchar();

	while (t--)
	{

		string str;
		getline(cin, str);
	
		Node *root = buildTree(str);
		Solution ob;
		ob.flatten(root);
		inorder(root);


		cout << "\n";
	}

	return 0;
}

// } Driver Code Ends
/*
1. Question link -- https://www.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1

2. Solution Link -- https://leetcode.com/problems/flatten-binary-tree-to-linked-list/solutions/5180333/4-approach-best-c-solution-brute-force-recursion-iterative-optimized-approach

3. Video link -- https://youtu.be/sWf7k1x9XR4?si=ghp8OzBBGlbZN7w3
*/