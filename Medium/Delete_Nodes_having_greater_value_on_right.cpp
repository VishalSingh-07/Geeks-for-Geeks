/*
Delete nodes having greater value on right

Given a singly linked list, remove all the nodes in the list which have any node on their right whose value is greater. (Not just immidiate Right , but entire List on the Right)

 

Example 1:

Input:
LinkedList = 12->15->10->11->5->6->2->3
Output: 15 11 6 3
Explanation: Since, 12, 10, 5 and 2 are
the elements which have greater elements
on the following nodes. So, after deleting
them, the linked list would like be 15,
11, 6, 3.


Example 2:

Input:
LinkedList = 10->20->30->40->50->60
Output: 60
Explanation: All the nodes except the last
node has a greater value node on its right,
so all the nodes except the last node must
be removed.
Your Task:
The task is to complete the function compute() which should modify the list as required and return the head of the modified linked list. The printing is done by the driver code,

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ size of linked list ≤ 105
1 ≤ element of linked list ≤ 105
Note: Try to solve the problem without using any extra space.

*/

//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

// Optimized Approach
// Time complexity -> O(n) and Space -> (1)

class Solution
{
private:
    // Function to reverse a linked list
    Node *reverse(Node *head)
    {
        Node *p = head;   // Pointer to traverse the original list
        Node *q = NULL;   // Previous node during reversal
        Node *r = NULL;   // Next node during reversal
        
        while (p != NULL)
        {
            r = q;         // Store the previous node
            q = p;         // Move q to the current node
            p = p->next;   // Move p to the next node
            q->next = r;   // Make the current node point to the previous node
        }
        head = q;         // Update the head to the last node (new start of reversed list)
    }

public:
    // Function to compute the modified linked list
    Node *compute(Node *head)
    {
        head = reverse(head);  // Reverse the linked list
        
        Node *temp = head;     // Temporary pointer for traversal
        int maxi = INT_MIN;    // Variable to store the maximum value encountered
        
        // Traverse the list to find the maximum and remove nodes with lesser values
        while (temp->next != NULL)
        {
            maxi = max(temp->data, maxi);  // Update the maximum value
            
            // If the next node's value is smaller than the maximum, skip the next node
            if (temp->next->data < maxi)
            {
                temp->next = temp->next->next;  // Skip the next node
            }
            else
            {
                temp = temp->next;  // Move to the next node
            }
        }
        
        head = reverse(head);  // Reverse the list again to restore the original order
        return head;           // Return the modified linked list
    }
};


   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1