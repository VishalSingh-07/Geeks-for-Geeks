/*
Nth node from end of linked list

Given a linked list consisting of L nodes and given a number N. The task is to find the Nth node from the end of the linked list.

Example 1:

Input:
N = 2
LinkedList: 1->2->3->4->5->6->7->8->9
Output: 8
Explanation: In the first example, there
are 9 nodes in linked list and we need
to find 2nd node from end. 2nd node
from end is 8.  


Example 2:

Input:
N = 5
LinkedList: 10->5->100->5
Output: -1
Explanation: In the second example, there
are 4 nodes in the linked list and we
need to find 5th from the end. Since 'n'
is more than the number of nodes in the
linked list, the output is -1.


Your Task:
The task is to complete the function getNthFromLast() which takes two arguments: reference to head and N and you need to return Nth from the end or -1 in case node doesn't exist.

Note:
Try to solve in a single traversal.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= L <= 106
1 <= N <= 106
*/

//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

    cout<<getNthFromLast(head, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends


/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

// Brute Force Approach
// Time complexity -> O(2n) ~ O(n) and Space -> O(1)
//Function to find the data of nth node from the end of a linked list.
// int getNthFromLast(Node *head, int n)
// {
//       // Your code here
//     int count=0;
//     Node *temp=head;
//     Node *del;
//     while(temp!=NULL)
//     {
//         count++;
//         temp=temp->next;
//     }
//     if(n>count)
//     {
//         return -1;
//     }
//     if(count==n)
//     {
//         del=head;
//         head=head->next;
//         return del->data;
//     }
//     int pos=count-n;
//     del=head;
//     Node *q=NULL;
//     while(pos--)
//     {
//         q=del;
//         del=del->next;
//     }
//     q->next=del->next;
//     return del->data;
// }


// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
    // Your code here
    Node *slow=head,*fast=head,*del;
    while(n--)
    {
        if(fast!=NULL)
        {
            fast=fast->next;   
        }
        else
        {
            return -1;
        }
    }
    if(fast==NULL)
    {
        return head->data;
    }
    while(fast->next!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }
    del=slow->next;
    slow->next=slow->next->next;
    return del->data;
       
}



/*
1. Question link -- https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1

2. Solution link -- https://leetcode.com/problems/remove-nth-node-from-end-of-list/solutions/3390761/2-approach-easy-c-solution-brute-force-and-optimized-approach/

3. Video link --https://youtu.be/Lhu3MsXZy-Q
*/