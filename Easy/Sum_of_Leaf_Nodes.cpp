//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

int sumLeaf(Node* root);

/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout<<sumLeaf(root)<<endl;
  }
  return 0;
}

// } Driver Code Ends


/*Structure of the node of the binary tree is as
struct Node
{
	int data;
	Node *left, *right;
};*/
// function should return the sum of all the 
// leaf nodes of the binary tree 

// Brute Force Approach
// Time complexity -> O(n) and Space -> O(n)
int recSum(Node *root)
{
    int x,y;
    if(root!=NULL)
    {
        x=recSum(root->left);
        y=recSum(root->right);
        if(root->left==NULL && root->right==NULL)
        {
            return x+y+root->data;
        }
        else
        {
            return x+y;
        }
    }
    return 0;
}
int sumLeaf(Node* root)
{
    // Code here
    return recSum(root);
}


// Optimized Approach
// Time complexity -> O(n) and Space -> O(n)
int sumLeaf(Node* root)
{
    // Code here
    if(root==NULL)
    {
        return 0;
    }
    else if(root->left==NULL && root->right==NULL)
    {
        return root->data;
    }
    else
    {
        return sumLeaf(root->left)+sumLeaf(root->right);
    }
}

// Question link -- https://practice.geeksforgeeks.org/problems/sum-of-leaf-nodes/1