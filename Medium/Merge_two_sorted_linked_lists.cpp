/*
Merge two sorted linked lists

Given two sorted linked lists consisting of N and M nodes respectively. The task is to merge both of the list (in-place) and return head of the merged list.
 

Example 1:

Input:
N = 4, M = 3 
valueN[] = {5,10,15,40}
valueM[] = {2,3,20}
Output: 2 3 5 10 15 20 40
Explanation: After merging the two linked
lists, we have merged list as 2, 3, 5,
10, 15, 20, 40.


Example 2:

Input:
N = 2, M = 2
valueN[] = {1,1}
valueM[] = {2,4}
Output:1 1 2 4
Explanation: After merging the given two
linked list , we have 1, 1, 2, 4 as
output.


Your Task:
The task is to complete the function sortedMerge() which takes references to the heads of two linked lists as the arguments and returns the head of merged linked list.

Expected Time Complexity : O(n+m)
Expected Auxilliary Space : O(1)

Constraints:
1 <= N, M <= 104
0 <= Node's data <= 105
*/


//{ Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends


 

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to merge two sorted linked list.

// Optimized Approach
// Time complexity -> O(n+m) and Space -> O(1)
Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    if(head1==NULL)
    {
        return head2;
    }
    if(head2==NULL)
    {
        return head1;
    }
    struct Node *third,*last;
    if(head1->data<head2->data)
    {
        third=last=head1;
        head1=head1->next;
        last->next=NULL;
    }
    else // head1->data > head2->data
    {
        third=last=head2;
        head2=head2->next;
        last->next=NULL;
        
    }
    while(head1!=NULL  && head2!=NULL)
    {
        if(head1->data<head2->data)
        {
            last->next=head1;
            last=head1;
            head1=head1->next;
            last->next=NULL;
        }
        else
        {
            last->next=head2;
            last=head2;
            head2=head2->next;
            last->next=NULL;
        }
    }
    if(head1!=NULL)
    {
        last->next=head1;
    }
    else
    {
        last->next=head2;
    }
    return third;
}  


/*
1. Question link -- https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1

2. Solution link -- https://leetcode.com/problems/merge-two-sorted-lists/solutions/3381613/optimized-approach-easy-c-solution-t-c-o-n-and-s-c-o-1/

*/