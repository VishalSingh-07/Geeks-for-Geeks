/*
Construct Binary Tree from Parent Array

Given an array parent that is used to represent a tree. The array indices (0-based indexing) are the values of the tree nodes and parent[i] denotes the parent node of a particular node. The parent of the root node would always be -1, as there is no parent for the root. Construct the standard linked representation of Binary Tree from this array representation and return the root node of the constructed tree.

Note: If two elements have the same parent, the one that appears first in the array will be the left child and the other is the right child. You don't need to print anything, the driver code will print the level order traversal of the returned root node to verify the output.

Examples:

Input: parent[] = [-1, 0, 0, 1, 1, 3,5]
Output: 0 1 2 3 4 5 6
Explanation: the tree generated
will have a structure like 
          0
        /   \
       1     2
      / \
     3   4
    /
   5
 /
6



Input: parent[] = [2, 0, -1]
Output: 2 0 1
Explanation: the tree generated will
have a sturcture like
             2
            /   
           0      
          /   
         1     


Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
- 1 ≤ parent.size() ≤ 103
*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

void sort_and_print(vector<int>& v) {
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    v.clear();
}

void printLevelOrder(struct Node* root) {
    vector<int> v;
    queue<Node*> q;

    q.push(root);

    Node* next_row = NULL;

    while (!q.empty()) {
        Node* n = q.front();
        q.pop();

        if (n == next_row) {
            sort_and_print(v);
            next_row = NULL;
        }

        v.push_back(n->data);

        if (n->left) {
            q.push(n->left);
            if (next_row == NULL)
                next_row = n->left;
        }

        if (n->right) {
            q.push(n->right);
            if (next_row == NULL)
                next_row = n->right;
        }
    }
    sort_and_print(v);
}

Node* createTree(int parent[], int n);

/* Driver program to test above function*/


// } Driver Code Ends
/* node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */


// Optimized Approach
// Time complexity -> O(n) and Space -> O(n)
/*

Let's dry run the given code with the parent array ([-1, 0, 0, 1, 1, 3, 5]).

### Step-by-Step Execution

1. **Initialization:**
    - `n = 7` (size of the parent array)
    - `mpp` is an unordered map to store nodes.
    - `root` is initially set to `nullptr`.

2. **First loop:** (Create nodes and determine the root)
    - For `i = 0`:
        - `parent[0] = -1`
        - Create a new node with value `0` and set it as the root.
        - `mpp[0] = new Node(0)`
        - `root = mpp[0]` (root points to the node with value `0`)
    - For `i = 1`:
        - `parent[1] = 0`
        - Create a new node with value `1`
        - `mpp[1] = new Node(1)`
    - For `i = 2`:
        - `parent[2] = 0`
        - Create a new node with value `2`
        - `mpp[2] = new Node(2)`
    - For `i = 3`:
        - `parent[3] = 1`
        - Create a new node with value `3`
        - `mpp[3] = new Node(3)`
    - For `i = 4`:
        - `parent[4] = 1`
        - Create a new node with value `4`
        - `mpp[4] = new Node(4)`
    - For `i = 5`:
        - `parent[5] = 3`
        - Create a new node with value `5`
        - `mpp[5] = new Node(5)`
    - For `i = 6`:
        - `parent[6] = 5`
        - Create a new node with value `6`
        - `mpp[6] = new Node(6)`

3. **Second loop:** (Link nodes to form the tree)
    - For `i = 0`:
        - `parent[0] = -1` (skip as it's the root)
    - For `i = 1`:
        - `parent[1] = 0`
        - `parentNode = mpp[0]` (node with value `0`)
        - `childNode = mpp[1]` (node with value `1`)
        - `parentNode->left` is `nullptr`
        - Set `parentNode->left = childNode`
    - For `i = 2`:
        - `parent[2] = 0`
        - `parentNode = mpp[0]` (node with value `0`)
        - `childNode = mpp[2]` (node with value `2`)
        - `parentNode->left` is not `nullptr`
        - Set `parentNode->right = childNode`
    - For `i = 3`:
        - `parent[3] = 1`
        - `parentNode = mpp[1]` (node with value `1`)
        - `childNode = mpp[3]` (node with value `3`)
        - `parentNode->left` is `nullptr`
        - Set `parentNode->left = childNode`
    - For `i = 4`:
        - `parent[4] = 1`
        - `parentNode = mpp[1]` (node with value `1`)
        - `childNode = mpp[4]` (node with value `4`)
        - `parentNode->left` is not `nullptr`
        - Set `parentNode->right = childNode`
    - For `i = 5`:
        - `parent[5] = 3`
        - `parentNode = mpp[3]` (node with value `3`)
        - `childNode = mpp[5]` (node with value `5`)
        - `parentNode->left` is `nullptr`
        - Set `parentNode->left = childNode`
    - For `i = 6`:
        - `parent[6] = 5`
        - `parentNode = mpp[5]` (node with value `5`)
        - `childNode = mpp[6]` (node with value `6`)
        - `parentNode->left` is `nullptr`
        - Set `parentNode->left = childNode`

### Final Tree Structure

The resulting tree will be:

```
       0
      / \
     1   2
    / \
   3   4
  /
 5
/
6
```

- Node `0` is the root.
- Node `1` is the left child of `0`.
- Node `2` is the right child of `0`.
- Node `3` is the left child of `1`.
- Node `4` is the right child of `1`.
- Node `5` is the left child of `3`.
- Node `6` is the left child of `5`.

The code correctly constructs the binary tree from the given parent array.


*/


class Solution {
  public:
    // Function to construct binary tree from parent array.
    Node *createTree(vector<int> parent) {
        // Your code here
        int n=parent.size();
        unordered_map<int,Node*> mpp;
        Node *root=nullptr;
        for(int i=0;i<n;i++){
            mpp[i]=new Node(i);
            if(parent[i]==-1){
                root=mpp[i];
            }
        }
        
        for(int i=0;i<n;i++){
            if(parent[i]!=-1){
                Node *parentNode=mpp[parent[i]];
                Node *childNode=mpp[i];
                if(parentNode->left==nullptr){
                    parentNode->left=childNode;
                }else{
                    parentNode->right=childNode;
                }
            }
            
        }
        return root;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a.push_back(x);
        }

        Solution ob;

        Node* res = ob.createTree(a);

        printLevelOrder(res);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends


/*
1. Question link -- https://www.geeksforgeeks.org/problems/construct-binary-tree-from-parent-array/1

2. Video link -- https://youtu.be/jYrGGiFUbsE?feature=shared
*/